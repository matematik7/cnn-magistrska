#!/usr/bin/env python3
import os
import random
import shutil
import time

import numpy as np
import cv2
import tensorflow as tf

from darkflow.net.build import TFNet

images = '../VOC2007/JPEGImages/'

last_layer_size = 11


def _iterate_files():
    for subdir, dirs, files in os.walk(images):
        for file in files:
            yield os.path.join(subdir, file)


def resize_input(im):
    w = 32*last_layer_size
    h = w
    imsz = cv2.resize(im, (w, h))
    imsz = imsz / 255.
    imsz = imsz[:, :, ::-1]
    return imsz


tfnet = TFNet({"model": "tiny-yolo-voc.cfg", "load": "tiny-yolo-voc.weights"})

shutil.rmtree('detections-tf', ignore_errors=True)
shutil.rmtree('groundtruths-tf', ignore_errors=True)
os.mkdir('detections-tf')
os.mkdir('groundtruths-tf')

with tfnet.graph.as_default():
    layers = tfnet.darknet.layers

    def _get_var(layer, name):
        return tf.get_variable(
            'layer_%d_%s' % (layer, name),
            shape=layers[layer].wshape[name],
            initializer=layers[layer].w[name],
        )

    inpt = tf.placeholder(
        tf.float32, shape=(1, 32*last_layer_size, 32*last_layer_size, 3))

    conv1 = tf.nn.conv2d(
        inpt, layers[0].w['kernel'],
        strides=[1, 1, 1, 1], padding='SAME')

    batch1 = tf.nn.batch_normalization(
        conv1,
        _get_var(0, 'moving_mean'),
        _get_var(0, 'moving_variance'),
        offset=layers[0].w['biases'],
        scale=_get_var(0, 'gamma'),
        variance_epsilon=1e-5,
    )

    leaky1 = tf.nn.leaky_relu(batch1, alpha=.1)

    maxpool1 = tf.nn.max_pool(
        leaky1,
        ksize=[1, 2, 2, 1],
        strides=[1, 2, 2, 1],
        padding='SAME',
    )

    conv2 = tf.nn.conv2d(
        maxpool1, layers[3].w['kernel'],
        strides=[1, 1, 1, 1], padding='SAME')

    batch2 = tf.nn.batch_normalization(
        conv2,
        _get_var(3, 'moving_mean'),
        _get_var(3, 'moving_variance'),
        offset=layers[3].w['biases'],
        scale=_get_var(3, 'gamma'),
        variance_epsilon=1e-5,
    )

    leaky2 = tf.nn.leaky_relu(batch2, alpha=.1)

    maxpool2 = tf.nn.max_pool(
        leaky2,
        ksize=[1, 2, 2, 1],
        strides=[1, 2, 2, 1],
        padding='SAME',
    )

    conv3 = tf.nn.conv2d(
        maxpool2, layers[6].w['kernel'],
        strides=[1, 1, 1, 1], padding='SAME')

    batch3 = tf.nn.batch_normalization(
        conv3,
        _get_var(6, 'moving_mean'),
        _get_var(6, 'moving_variance'),
        offset=layers[6].w['biases'],
        scale=_get_var(6, 'gamma'),
        variance_epsilon=1e-5,
    )

    leaky3 = tf.nn.leaky_relu(batch3, alpha=.1)

    maxpool3 = tf.nn.max_pool(
        leaky3,
        ksize=[1, 2, 2, 1],
        strides=[1, 2, 2, 1],
        padding='SAME',
    )

    conv4 = tf.nn.conv2d(
        maxpool3, layers[9].w['kernel'],
        strides=[1, 1, 1, 1], padding='SAME')

    batch4 = tf.nn.batch_normalization(
        conv4,
        _get_var(9, 'moving_mean'),
        _get_var(9, 'moving_variance'),
        offset=layers[9].w['biases'],
        scale=_get_var(9, 'gamma'),
        variance_epsilon=1e-5,
    )

    leaky4 = tf.nn.leaky_relu(batch4, alpha=.1)

    maxpool4 = tf.nn.max_pool(
        leaky4,
        ksize=[1, 2, 2, 1],
        strides=[1, 2, 2, 1],
        padding='SAME',
    )

    conv5 = tf.nn.conv2d(
        maxpool4, layers[12].w['kernel'],
        strides=[1, 1, 1, 1], padding='SAME')

    batch5 = tf.nn.batch_normalization(
        conv5,
        _get_var(12, 'moving_mean'),
        _get_var(12, 'moving_variance'),
        offset=layers[12].w['biases'],
        scale=_get_var(12, 'gamma'),
        variance_epsilon=1e-5,
    )

    leaky5 = tf.nn.leaky_relu(batch5, alpha=.1)

    maxpool5 = tf.nn.max_pool(
        leaky5,
        ksize=[1, 2, 2, 1],
        strides=[1, 2, 2, 1],
        padding='SAME',
    )

    conv6 = tf.nn.conv2d(
        maxpool5, layers[15].w['kernel'],
        strides=[1, 1, 1, 1], padding='SAME')

    batch6 = tf.nn.batch_normalization(
        conv6,
        _get_var(15, 'moving_mean'),
        _get_var(15, 'moving_variance'),
        offset=layers[15].w['biases'],
        scale=_get_var(15, 'gamma'),
        variance_epsilon=1e-5,
    )

    leaky6 = tf.nn.leaky_relu(batch6, alpha=.1)

    maxpool6 = tf.nn.max_pool(
        leaky6,
        ksize=[1, 2, 2, 1],
        strides=[1, 1, 1, 1],
        padding='SAME',
    )

    conv7 = tf.nn.conv2d(
        maxpool6, layers[18].w['kernel'],
        strides=[1, 1, 1, 1], padding='SAME')

    batch7 = tf.nn.batch_normalization(
        conv7,
        _get_var(18, 'moving_mean'),
        _get_var(18, 'moving_variance'),
        offset=layers[18].w['biases'],
        scale=_get_var(18, 'gamma'),
        variance_epsilon=1e-5,
    )

    leaky7 = tf.nn.leaky_relu(batch7, alpha=.1)

    conv8 = tf.nn.conv2d(
        leaky7, layers[20].w['kernel'],
        strides=[1, 1, 1, 1], padding='SAME')

    batch8 = tf.nn.batch_normalization(
        conv8,
        _get_var(20, 'moving_mean'),
        _get_var(20, 'moving_variance'),
        offset=layers[20].w['biases'],
        scale=_get_var(20, 'gamma'),
        variance_epsilon=1e-5,
    )

    leaky8 = tf.nn.leaky_relu(batch8, alpha=.1)

    conv9 = tf.nn.conv2d(
        leaky8, layers[22].w['kernel'],
        strides=[1, 1, 1, 1], padding='SAME')

    biased9 = tf.nn.bias_add(conv9, layers[22].w['biases'])

    output = tf.identity(biased9)

    with tf.Session() as sess:
        sess.run(tf.global_variables_initializer())

        files = list(_iterate_files())
        random.shuffle(files)
        for i, img_file in enumerate(files):
            start_time = time.time()

            fid = img_file.split('/')[-1][:-4]

            orig_img = cv2.imread(img_file)
            if orig_img is None:
                continue

            img = resize_input(orig_img)
            img = np.expand_dims(img, 0)
            h, w, _ = orig_img.shape

            out = sess.run(output, {inpt: img})[0]

            threshold = 0
            boxes = tfnet.framework.findboxes(out)

            with open('detections-tf/{}.txt'.format(fid), 'w') as fout:
                for box in boxes:
                    box = tfnet.framework.process_box(box, h, w, threshold)
                    if not box:
                        continue

                    left, right, top, bottom, cls, idx, prob = box

                    fout.write(' '.join(str(x) for x in [cls, prob, left, top, right, bottom]) + '\n')

            shutil.copyfile('groundtruths/{}.txt'.format(fid), 'groundtruths-tf/{}.txt'.format(fid))

            print(i, time.time() - start_time)
