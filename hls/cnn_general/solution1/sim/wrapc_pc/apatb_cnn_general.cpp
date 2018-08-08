// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.4
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#define AP_INT_MAX_W 32678

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "ap_stream.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->


// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "in_V_V"
#define AUTOTB_TVIN_in_V_V  "../tv/cdatafile/c.cnn_general.autotvin_in_V_V.dat"
#define WRAPC_STREAM_SIZE_IN_in_V_V  "../tv/stream_size/stream_size_in_in_V_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_in_V_V  "../tv/stream_size/stream_ingress_status_in_V_V.dat"
// wrapc file define: "out_V_V"
#define AUTOTB_TVOUT_out_V_V  "../tv/cdatafile/c.cnn_general.autotvout_out_V_V.dat"
#define AUTOTB_TVIN_out_V_V  "../tv/cdatafile/c.cnn_general.autotvin_out_V_V.dat"
#define WRAPC_STREAM_SIZE_OUT_out_V_V  "../tv/stream_size/stream_size_out_out_V_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_out_V_V  "../tv/stream_size/stream_egress_status_out_V_V.dat"
// wrapc file define: "size"
#define AUTOTB_TVIN_size  "../tv/cdatafile/c.cnn_general.autotvin_size.dat"
// wrapc file define: "in_layers"
#define AUTOTB_TVIN_in_layers  "../tv/cdatafile/c.cnn_general.autotvin_in_layers.dat"
// wrapc file define: "out_layers"
#define AUTOTB_TVIN_out_layers  "../tv/cdatafile/c.cnn_general.autotvin_out_layers.dat"
// wrapc file define: "stream_weights"
#define AUTOTB_TVIN_stream_weights  "../tv/cdatafile/c.cnn_general.autotvin_stream_weights.dat"
// wrapc file define: "max_type"
#define AUTOTB_TVIN_max_type  "../tv/cdatafile/c.cnn_general.autotvin_max_type.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "out_V_V"
#define AUTOTB_TVOUT_PC_out_V_V  "../tv/rtldatafile/rtl.cnn_general.autotvout_out_V_V.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			in_V_V_depth = 0;
			out_V_V_depth = 0;
			size_depth = 0;
			in_layers_depth = 0;
			out_layers_depth = 0;
			stream_weights_depth = 0;
			max_type_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{in_V_V " << in_V_V_depth << "}\n";
			total_list << "{out_V_V " << out_V_V_depth << "}\n";
			total_list << "{size " << size_depth << "}\n";
			total_list << "{in_layers " << in_layers_depth << "}\n";
			total_list << "{out_layers " << out_layers_depth << "}\n";
			total_list << "{stream_weights " << stream_weights_depth << "}\n";
			total_list << "{max_type " << max_type_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int in_V_V_depth;
		int out_V_V_depth;
		int size_depth;
		int in_layers_depth;
		int out_layers_depth;
		int stream_weights_depth;
		int max_type_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern void cnn_general (
hls::stream<ap_fixed<24, 7, (ap_q_mode) 5, (ap_o_mode)0, 0> > (&in),
hls::stream<ap_fixed<24, 7, (ap_q_mode) 5, (ap_o_mode)0, 0> > (&out),
int size,
int in_layers,
int out_layers,
bool stream_weights,
int max_type);

void AESL_WRAP_cnn_general (
hls::stream<ap_fixed<24, 7, (ap_q_mode) 5, (ap_o_mode)0, 0> > (&in),
hls::stream<ap_fixed<24, 7, (ap_q_mode) 5, (ap_o_mode)0, 0> > (&out),
int size,
int in_layers,
int out_layers,
bool stream_weights,
int max_type)
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;

		// pop stream input: "in"
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_in_V_V, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_in_V_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_in_V_V, AESL_token); // pop_size
			int aesl_tmp_1 = atoi(AESL_token.c_str());
			for (int i = 0; i < aesl_tmp_1; i++)
			{
				in.read();
			}
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_in_V_V, AESL_token); // [[/transaction]]
		}

		// define output stream variables: "out"
		std::vector<ap_fixed<24, 7, (ap_q_mode) 5, (ap_o_mode)0, 0> > aesl_tmp_3;
		int aesl_tmp_4;
		int aesl_tmp_5 = 0;

		// read output stream size: "out"
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_out_V_V, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_out_V_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_out_V_V, AESL_token); // pop_size
			aesl_tmp_4 = atoi(AESL_token.c_str());
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_out_V_V, AESL_token); // [[/transaction]]
		}

		// output port post check: "out_V_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_out_V_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_out_V_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_out_V_V, AESL_token); // data

			std::vector<sc_bv<24> > out_V_V_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'out_V_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'out_V_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					out_V_V_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_out_V_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_out_V_V))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_4)
			{
				aesl_tmp_4 = i;
			}

			if (aesl_tmp_4 > 0 && aesl_tmp_3.size() < aesl_tmp_4)
			{
				int aesl_tmp_3_size = aesl_tmp_3.size();

				for (int tmp_aesl_tmp_3 = 0; tmp_aesl_tmp_3 < aesl_tmp_4 - aesl_tmp_3_size; tmp_aesl_tmp_3++)
				{
					ap_fixed<24, 7, (ap_q_mode) 5, (ap_o_mode)0, 0> tmp;
					aesl_tmp_3.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: out_V_V
				{
					// bitslice(23, 0)
					// {
						// celement: out.V.V(23, 0)
						// {
							sc_lv<24>* out_V_V_lv0_0_0_1 = new sc_lv<24>[aesl_tmp_4 - aesl_tmp_5];
						// }
					// }

					// bitslice(23, 0)
					{
						int hls_map_index = 0;
						// celement: out.V.V(23, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								if (&(aesl_tmp_3[0]) != NULL) // check the null address if the c port is array or others
								{
									out_V_V_lv0_0_0_1[hls_map_index].range(23, 0) = sc_bv<24>(out_V_V_pc_buffer[hls_map_index].range(23, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(23, 0)
					{
						int hls_map_index = 0;
						// celement: out.V.V(23, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : aesl_tmp_3[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : aesl_tmp_3[0]
								// output_left_conversion : (aesl_tmp_3[i_0]).range()
								// output_type_conversion : (out_V_V_lv0_0_0_1[hls_map_index]).to_string(SC_BIN).c_str()
								if (&(aesl_tmp_3[0]) != NULL) // check the null address if the c port is array or others
								{
									(aesl_tmp_3[i_0]).range() = (out_V_V_lv0_0_0_1[hls_map_index]).to_string(SC_BIN).c_str();
									hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// push back output stream: "out"
		for (int i = 0; i < aesl_tmp_4; i++)
		{
			out.write(aesl_tmp_3[i]);
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "in_V_V"
		char* tvin_in_V_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_in_V_V);
		char* wrapc_stream_size_in_in_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_in_V_V);
		char* wrapc_stream_ingress_status_in_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_in_V_V);

		// "out_V_V"
		char* tvin_out_V_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_out_V_V);
		char* tvout_out_V_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_out_V_V);
		char* wrapc_stream_size_out_out_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_out_V_V);
		char* wrapc_stream_egress_status_out_V_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_out_V_V);

		// "size"
		char* tvin_size = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_size);

		// "in_layers"
		char* tvin_in_layers = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_in_layers);

		// "out_layers"
		char* tvin_out_layers = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_out_layers);

		// "stream_weights"
		char* tvin_stream_weights = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_stream_weights);

		// "max_type"
		char* tvin_max_type = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_max_type);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// dump stream tvin: "in"
		std::vector<ap_fixed<24, 7, (ap_q_mode) 5, (ap_o_mode)0, 0> > aesl_tmp_0;
		int aesl_tmp_1 = 0;
		while (!in.empty())
		{
			aesl_tmp_0.push_back(in.read());
			aesl_tmp_1++;
		}

		// dump stream tvin: "out"
		std::vector<ap_fixed<24, 7, (ap_q_mode) 5, (ap_o_mode)0, 0> > aesl_tmp_3;
		int aesl_tmp_4 = 0;
		while (!out.empty())
		{
			aesl_tmp_3.push_back(out.read());
			aesl_tmp_4++;
		}

		// [[transaction]]
		sprintf(tvin_size, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_size, tvin_size);

		sc_bv<32> size_tvin_wrapc_buffer;

		// RTL Name: size
		{
			// bitslice(31, 0)
			{
				// celement: size(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : size
						// sub_1st_elem          : 
						// ori_name_1st_elem     : size
						// regulate_c_name       : size
						// input_type_conversion : size
						if (&(size) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> size_tmp_mem;
							size_tmp_mem = size;
							size_tvin_wrapc_buffer.range(31, 0) = size_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_size, "%s\n", (size_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_size, tvin_size);
		}

		tcl_file.set_num(1, &tcl_file.size_depth);
		sprintf(tvin_size, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_size, tvin_size);

		// [[transaction]]
		sprintf(tvin_in_layers, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_in_layers, tvin_in_layers);

		sc_bv<32> in_layers_tvin_wrapc_buffer;

		// RTL Name: in_layers
		{
			// bitslice(31, 0)
			{
				// celement: in_layers(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : in_layers
						// sub_1st_elem          : 
						// ori_name_1st_elem     : in_layers
						// regulate_c_name       : in_layers
						// input_type_conversion : in_layers
						if (&(in_layers) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> in_layers_tmp_mem;
							in_layers_tmp_mem = in_layers;
							in_layers_tvin_wrapc_buffer.range(31, 0) = in_layers_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_in_layers, "%s\n", (in_layers_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_in_layers, tvin_in_layers);
		}

		tcl_file.set_num(1, &tcl_file.in_layers_depth);
		sprintf(tvin_in_layers, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_in_layers, tvin_in_layers);

		// [[transaction]]
		sprintf(tvin_out_layers, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_out_layers, tvin_out_layers);

		sc_bv<32> out_layers_tvin_wrapc_buffer;

		// RTL Name: out_layers
		{
			// bitslice(31, 0)
			{
				// celement: out_layers(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : out_layers
						// sub_1st_elem          : 
						// ori_name_1st_elem     : out_layers
						// regulate_c_name       : out_layers
						// input_type_conversion : out_layers
						if (&(out_layers) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> out_layers_tmp_mem;
							out_layers_tmp_mem = out_layers;
							out_layers_tvin_wrapc_buffer.range(31, 0) = out_layers_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_out_layers, "%s\n", (out_layers_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_out_layers, tvin_out_layers);
		}

		tcl_file.set_num(1, &tcl_file.out_layers_depth);
		sprintf(tvin_out_layers, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_out_layers, tvin_out_layers);

		// [[transaction]]
		sprintf(tvin_stream_weights, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_stream_weights, tvin_stream_weights);

		sc_bv<1> stream_weights_tvin_wrapc_buffer;

		// RTL Name: stream_weights
		{
			// bitslice(0, 0)
			{
				// celement: stream_weights(0, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : stream_weights
						// sub_1st_elem          : 
						// ori_name_1st_elem     : stream_weights
						// regulate_c_name       : stream_weights
						// input_type_conversion : stream_weights
						if (&(stream_weights) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<1> stream_weights_tmp_mem;
							stream_weights_tmp_mem = stream_weights;
							stream_weights_tvin_wrapc_buffer.range(0, 0) = stream_weights_tmp_mem.range(0, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_stream_weights, "%s\n", (stream_weights_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_stream_weights, tvin_stream_weights);
		}

		tcl_file.set_num(1, &tcl_file.stream_weights_depth);
		sprintf(tvin_stream_weights, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_stream_weights, tvin_stream_weights);

		// [[transaction]]
		sprintf(tvin_max_type, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_max_type, tvin_max_type);

		sc_bv<32> max_type_tvin_wrapc_buffer;

		// RTL Name: max_type
		{
			// bitslice(31, 0)
			{
				// celement: max_type(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : max_type
						// sub_1st_elem          : 
						// ori_name_1st_elem     : max_type
						// regulate_c_name       : max_type
						// input_type_conversion : max_type
						if (&(max_type) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> max_type_tmp_mem;
							max_type_tmp_mem = max_type;
							max_type_tvin_wrapc_buffer.range(31, 0) = max_type_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_max_type, "%s\n", (max_type_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_max_type, tvin_max_type);
		}

		tcl_file.set_num(1, &tcl_file.max_type_depth);
		sprintf(tvin_max_type, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_max_type, tvin_max_type);

		// push back input stream: "in"
		for (int i = 0; i < aesl_tmp_1; i++)
		{
			in.write(aesl_tmp_0[i]);
		}

		// push back input stream: "out"
		for (int i = 0; i < aesl_tmp_4; i++)
		{
			out.write(aesl_tmp_3[i]);
		}

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		cnn_general(in, out, size, in_layers, out_layers, stream_weights, max_type);

		CodeState = DUMP_OUTPUTS;
		// record input size to tv3: "in"
		int aesl_tmp_2 = in.size();

		// pop output stream: "out"
		int aesl_tmp_5 = aesl_tmp_4;
		aesl_tmp_4 = 0;
     aesl_tmp_3.clear();
		while (!out.empty())
		{
			aesl_tmp_3.push_back(out.read());
			aesl_tmp_4++;
		}

		// [[transaction]]
		sprintf(tvin_in_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_in_V_V, tvin_in_V_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, tvin_in_V_V);

		sc_bv<24>* in_V_V_tvin_wrapc_buffer = new sc_bv<24>[aesl_tmp_1 - aesl_tmp_2];

		// RTL Name: in_V_V
		{
			// bitslice(23, 0)
			{
				int hls_map_index = 0;
				// celement: in.V.V(23, 0)
				{
					// carray: (0) => (aesl_tmp_1 - aesl_tmp_2 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_1 - aesl_tmp_2 - 1; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : aesl_tmp_0[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : aesl_tmp_0[0]
						// regulate_c_name       : in_V_V
						// input_type_conversion : (aesl_tmp_0[i_0]).range().to_string(SC_BIN).c_str()
						if (&(aesl_tmp_0[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<24> in_V_V_tmp_mem;
							in_V_V_tmp_mem = (aesl_tmp_0[i_0]).range().to_string(SC_BIN).c_str();
							in_V_V_tvin_wrapc_buffer[hls_map_index].range(23, 0) = in_V_V_tmp_mem.range(23, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			sprintf(tvin_in_V_V, "%s\n", (in_V_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_in_V_V, tvin_in_V_V);
		}

		// dump stream ingress status to file
		sc_int<32> stream_ingress_size_in_V_V = aesl_tmp_1;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, stream_ingress_size_in_V_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, "\n");

		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			stream_ingress_size_in_V_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, stream_ingress_size_in_V_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, "\n");
		}

		tcl_file.set_num(aesl_tmp_1 - aesl_tmp_2, &tcl_file.in_V_V_depth);
		sprintf(tvin_in_V_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_in_V_V, tvin_in_V_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_in_V_V, tvin_in_V_V);

		// release memory allocation
		delete [] in_V_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_in_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_in_V_V, wrapc_stream_size_in_in_V_V);
		sprintf(wrapc_stream_size_in_in_V_V, "%d\n", aesl_tmp_1 - aesl_tmp_2);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_in_V_V, wrapc_stream_size_in_in_V_V);
		sprintf(wrapc_stream_size_in_in_V_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_in_V_V, wrapc_stream_size_in_in_V_V);

		// [[transaction]]
		sprintf(tvout_out_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_out_V_V, tvout_out_V_V);

		sc_bv<24>* out_V_V_tvout_wrapc_buffer = new sc_bv<24>[aesl_tmp_4 - aesl_tmp_5];

		// RTL Name: out_V_V
		{
			// bitslice(23, 0)
			{
				int hls_map_index = 0;
				// celement: out.V.V(23, 0)
				{
					// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
					for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : aesl_tmp_3[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : aesl_tmp_3[0]
						// regulate_c_name       : out_V_V
						// input_type_conversion : (aesl_tmp_3[i_0]).range().to_string(SC_BIN).c_str()
						if (&(aesl_tmp_3[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<24> out_V_V_tmp_mem;
							out_V_V_tmp_mem = (aesl_tmp_3[i_0]).range().to_string(SC_BIN).c_str();
							out_V_V_tvout_wrapc_buffer[hls_map_index].range(23, 0) = out_V_V_tmp_mem.range(23, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_4 - aesl_tmp_5; i++)
		{
			sprintf(tvout_out_V_V, "%s\n", (out_V_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_out_V_V, tvout_out_V_V);
		}

		tcl_file.set_num(aesl_tmp_4 - aesl_tmp_5, &tcl_file.out_V_V_depth);
		sprintf(tvout_out_V_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_out_V_V, tvout_out_V_V);

		// release memory allocation
		delete [] out_V_V_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_out_V_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_out_V_V, wrapc_stream_size_out_out_V_V);
		sprintf(wrapc_stream_size_out_out_V_V, "%d\n", aesl_tmp_4 - aesl_tmp_5);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_out_V_V, wrapc_stream_size_out_out_V_V);
		sprintf(wrapc_stream_size_out_out_V_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_out_V_V, wrapc_stream_size_out_out_V_V);

		// push back output stream: "out"
		for (int i = 0; i < aesl_tmp_4; i++)
		{
			out.write(aesl_tmp_3[i]);
		}

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "in_V_V"
		delete [] tvin_in_V_V;
		delete [] wrapc_stream_size_in_in_V_V;
		// release memory allocation: "out_V_V"
		delete [] tvout_out_V_V;
		delete [] tvin_out_V_V;
		delete [] wrapc_stream_size_out_out_V_V;
		// release memory allocation: "size"
		delete [] tvin_size;
		// release memory allocation: "in_layers"
		delete [] tvin_in_layers;
		// release memory allocation: "out_layers"
		delete [] tvin_out_layers;
		// release memory allocation: "stream_weights"
		delete [] tvin_stream_weights;
		// release memory allocation: "max_type"
		delete [] tvin_max_type;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

