/*
 *
 * step_5.h
 *
 * authors:
 * Marco Rabozzi (marco.rabozzi@polimi.it)
 * Emanuele Del Sozzo (emanuele.delsozzo@polimi.it)
 * Lorenzo Di Tucci (lorenzo.ditucci@polimi.it)
 *
 * Perform step 5 of five-point algorithm:
 * solve the 10-degree polynomial and recover its roots.
 */

#ifndef STEP_5_H
#define STEP_5_H

#include "utils.h"
#include "polysolve.h"

/*
 * Solve the 10-th degree polynomial and find up to 10 roots.
 * NOTE: 10 values are returned and invalid roots are set to -INFINITY.
 */
void step_5_streaming(
		hls::stream<my_type> &coeff_stream,
		hls::stream<my_type> &out,
		const int iterations)
{
	#pragma HLS INLINE
	#pragma HLS DATAFLOW

	polysolve_streaming(coeff_stream, out, iterations);

}

#endif
