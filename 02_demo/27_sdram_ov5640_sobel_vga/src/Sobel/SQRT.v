// megafunction wizard: %ALTSQRT%
// GENERATION: STANDARD
// VERSION: WM1.0
// MODULE: altsqrt 

// ============================================================
// File Name: SQRT.v
// Megafunction Name(s):
// 			altsqrt
//
// Simulation Library Files(s):
// 			altera_mf
// ============================================================
// ************************************************************
// THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
//
// 7.2 Build 207 03/18/2008 SP 3 SJ Full Version
// ************************************************************


//Copyright (C) 1991-2007 Altera Corporation
//Your use of Altera Corporation's design tools, logic functions 
//and other software and tools, and its AMPP partner logic 
//functions, and any output files from any of the foregoing 
//(including device programming or simulation files), and any 
//associated documentation or information are expressly subject 
//to the terms and conditions of the Altera Program License 
//Subscription Agreement, Altera MegaCore Function License 
//Agreement, or other applicable license agreement, including, 
//without limitation, that your use is for the sole purpose of 
//programming logic devices manufactured by Altera and sold by 
//Altera or its authorized distributors.  Please refer to the 
//applicable agreement for further details.


// synopsys translate_off
`timescale 1 ps / 1 ps
// synopsys translate_on
module SQRT (
	clk,
	radical,
	q,
	remainder);

	input	  clk;
	input	[31:0]  radical;
	output	[15:0]  q;
	output	[16:0]  remainder;

	wire [16:0] sub_wire0;
	wire [15:0] sub_wire1;
	wire [16:0] remainder = sub_wire0[16:0];
	wire [15:0] q = sub_wire1[15:0];

	altsqrt	altsqrt_component (
				.radical (radical),
				.clk (clk),
				.remainder (sub_wire0),
				.q (sub_wire1)
				// synopsys translate_off
				,
				.aclr (),
				.ena ()
				// synopsys translate_on
				);
	defparam
		altsqrt_component.pipeline = 2,
		altsqrt_component.q_port_width = 16,
		altsqrt_component.r_port_width = 17,
		altsqrt_component.width = 32;


endmodule

// ============================================================
// CNX file retrieval info
// ============================================================
// Retrieval info: PRIVATE: INTENDED_DEVICE_FAMILY STRING "Cyclone II"
// Retrieval info: PRIVATE: SYNTH_WRAPPER_GEN_POSTFIX STRING "0"
// Retrieval info: CONSTANT: PIPELINE NUMERIC "2"
// Retrieval info: CONSTANT: Q_PORT_WIDTH NUMERIC "16"
// Retrieval info: CONSTANT: R_PORT_WIDTH NUMERIC "17"
// Retrieval info: CONSTANT: WIDTH NUMERIC "32"
// Retrieval info: USED_PORT: clk 0 0 0 0 INPUT NODEFVAL clk
// Retrieval info: USED_PORT: q 0 0 16 0 OUTPUT NODEFVAL q[15..0]
// Retrieval info: USED_PORT: radical 0 0 32 0 INPUT NODEFVAL radical[31..0]
// Retrieval info: USED_PORT: remainder 0 0 17 0 OUTPUT NODEFVAL remainder[16..0]
// Retrieval info: CONNECT: @clk 0 0 0 0 clk 0 0 0 0
// Retrieval info: CONNECT: @radical 0 0 32 0 radical 0 0 32 0
// Retrieval info: CONNECT: q 0 0 16 0 @q 0 0 16 0
// Retrieval info: CONNECT: remainder 0 0 17 0 @remainder 0 0 17 0
// Retrieval info: LIBRARY: altera_mf altera_mf.altera_mf_components.all
// Retrieval info: GEN_FILE: TYPE_NORMAL SQRT.v TRUE
// Retrieval info: GEN_FILE: TYPE_NORMAL SQRT.inc FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL SQRT.cmp FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL SQRT.bsf FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL SQRT_inst.v FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL SQRT_bb.v FALSE
// Retrieval info: LIB_FILE: altera_mf
