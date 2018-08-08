#!/usr/bin/env python3
from functools import partial
import itertools

import numpy as np
import tensorflow as tf

from darkflow.net.build import TFNet

tfnet = TFNet({"model": "tiny-yolo-voc.cfg", "load": "tiny-yolo-voc.weights"})

output_c_file = "../vivado/cnn/cnn.sdk/cnnGeneral/src/weights.h"
fixed_point_shift = 24-7


with tfnet.graph.as_default():
    layers = tfnet.darknet.layers

    def _get_var(layer, name):
        return tf.get_variable(
            'layer_%d_%s' % (layer, name),
            shape=layers[layer].wshape[name],
            initializer=layers[layer].w[name],
        )

    layer_size = 352
    layer_numbers = [0, 3, 6, 9, 12, 15, 18, 20, 22][:3]
    #  control = [0b00000110, 0b00000110, 0b00000110, 0b00000110, 0b00000110, 0b00001111, 0b000000011, 0b000000011, 0b00000001]
    control = [0b00010110, 0b00000110, 0b00000110, 0b00000110, 0b00000110, 0b00001111, 0b000000011, 0b000000011, 0b00000001]
    gammas = [_get_var(layer, 'gamma') for layer in layer_numbers if layer < 22]
    variances = [_get_var(layer, 'moving_variance') for layer in layer_numbers if layer < 22]
    means = [_get_var(layer, 'moving_mean') for layer in layer_numbers if layer < 22]
    layer_sizes = []
    input_layers = []
    output_layers = []
    all_weights = []

    with tf.Session() as sess:
        sess.run(tf.global_variables_initializer())

        with open("weights.dat", "w") as output_file:
            np.savetxt(output_file, [len(layer_numbers)], fmt='%d')
            for i, layer in enumerate(layer_numbers):
                weights = sess.run(layers[layer].w['kernel'])
                bias = sess.run(layers[layer].w['biases'])
                if layer < 22:
                    gamma = sess.run(gammas[i])
                    variance = sess.run(variances[i])
                    mean = sess.run(means[i])

                    scale = [gamma[j]/np.sqrt(variance[j]+1e-5) for j in range(weights.shape[-1])]
                    add = [bias[j] - mean[j]*scale[j] for j in range(weights.shape[-1])]
                else:
                    # TODO: fix hack for different last layer shape
                    d1 = weights.shape
                    weights1 = np.append(np.zeros(d1), np.append(weights, np.zeros(d1), 0), 0)
                    d3 = weights1.shape
                    weights3 = np.append(np.zeros(d3), np.append(weights1, np.zeros(d3), 1), 1)
                    weights = weights3
                    scale = [1 for j in range(weights.shape[-1])]
                    add = [bias[j] for j in range(weights.shape[-1])]

                layer_sizes.append(layer_size)
                input_layers.append(weights.shape[-2])
                output_layers.append(weights.shape[-1])
                all_weights.append([])

                np.savetxt(output_file, [
                    layer_size, weights.shape[-2], weights.shape[-1],
                    control[i]], fmt='%d')
                print(weights.shape)

                if control[i] & 1:  # stream_weights
                    np.savetxt(output_file, [(scale[j], add[j]) for j in range(weights.shape[-1])])
                    all_weights[-1].extend(itertools.chain(*[(scale[j], add[j]) for j in range(weights.shape[-1])]))
                    for j in range(weights.shape[-1]):
                        np.savetxt(output_file, weights[:, :, :, j].flatten())
                        all_weights[-1].extend(weights[:, :, :, j].flatten())
                else:
                    for k in range(0, weights.shape[-1], 64):
                        out_size = min(weights.shape[-1], 64)
                        np.savetxt(output_file, [(scale[j+k], add[j+k]) for j in range(out_size)])
                        all_weights[-1].extend(itertools.chain(*[(scale[j+k], add[j+k]) for j in range(out_size)]))
                        for j in range(out_size):
                            np.savetxt(output_file, weights[:, :, :, j+k].flatten())
                            all_weights[-1].extend(weights[:, :, :, j+k].flatten())

                if layer_size > 13:
                    layer_size //= 2

def number_array(values, formatter=str):
    return "{" + ", ".join(map(formatter, values)) + "}"

def number_array_2d(data, formatter=str):
    return "{\n  " + "\n  ".join(map(partial(number_array, formatter=formatter), data)) + "\n}"

def to_fixed(value):
    intv = int(value * (1 << fixed_point_shift))
    return ", ".join(map(str, [intv&0xff, (intv >> 8)&0xff, (intv >> 16)&0xff]))

with open(output_c_file, "w") as cout:
    cout.write("int n = {};\n".format(len(layer_numbers)))
    cout.write("int layer_sizes[] = {};\n".format(number_array(layer_sizes)))
    cout.write("int input_layers[] = {};\n".format(number_array(input_layers)))
    cout.write("int output_layers[] = {};\n".format(number_array(output_layers)))
    cout.write("int controls[] = {};\n".format(number_array(control)))
    for i, values in enumerate(all_weights):
        cout.write("unsigned char weights{}[] = {};\n".format(i, number_array(values, formatter=to_fixed)))
    cout.write("unsigned char *weights[] = {};\n".format(number_array(["weights{}".format(i) for i in range(len(all_weights))])))
