/*
 *
 * memInterface.h
 *
 * authors:
 * Marco Rabozzi (marco.rabozzi@polimi.it)
 * Emanuele Del Sozzo (emanuele.delsozzo@polimi.it)
 * Lorenzo Di Tucci (lorenzo.ditucci@polimi.it)
 *
 *
 * This file contains a set of utility to read/write data from/to memory,
 * and push/pop to/from hls::stream
 * The purpose of wrapper functions is to invoke N times the inner function,
 * in order to enable overlapping computations among different couples of
 * 5 points
 *
 */

#ifndef MEM_INTERFACE_H
#define MEM_INTERFACE_H

#include "utils.h"

/*
 * hls::stream to master axi
 */
template<
	typename Type,
	int size>
void stream2axi_inner(hls::stream<Type> &in, Type* out){
	s2a_loop_0:for(int i = 0; i < size; i++){
#pragma HLS PIPELINE
		Type val = in.read();
		out[i] = val;
	}
}

/*
 * hls::stream to master axi wrapper
 */
template<
	typename Type,
	int size>
void stream2axi(hls::stream<Type> &in, Type* out, const int iter){
	s2a_loop_0:for(int i = 0; i < size*iter; i++){
#pragma HLS PIPELINE
		Type val = in.read();
		out[i] = val;
	}
}

/*
 * Master axi to hls::stream
 */
template<
	typename Type,
	int size>
void axi2stream_inner(Type* in, hls::stream<Type> &out){
	a2s_loop_0:for(int i = 0; i < size; i++){
#pragma HLS PIPELINE
		out.write(in[i]);
	}
}

/*
 * Master axi to hls::stream wrapper
 */
template<
	typename Type,
	int size>
void axi2stream(Type* in, hls::stream<Type> &out, const int iter){
	a2s_loop_0:for(int i = 0; i < size*iter; i++){
#pragma HLS PIPELINE
		out.write(in[i]);
	}

}

#endif
