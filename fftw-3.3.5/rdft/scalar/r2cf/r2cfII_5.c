/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sat Jul 30 16:47:21 EDT 2016 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_r2cf.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -n 5 -name r2cfII_5 -dft-II -include r2cfII.h */

/*
 * This function contains 12 FP additions, 7 FP multiplications,
 * (or, 7 additions, 2 multiplications, 5 fused multiply/add),
 * 17 stack variables, 4 constants, and 10 memory accesses
 */
#include "r2cfII.h"

static void r2cfII_5(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(20, rs), MAKE_VOLATILE_STRIDE(20, csr), MAKE_VOLATILE_STRIDE(20, csi)) {
	       E T1, T2, T3, T5, T6;
	       T1 = R0[0];
	       T2 = R0[WS(rs, 1)];
	       T3 = R1[WS(rs, 1)];
	       T5 = R0[WS(rs, 2)];
	       T6 = R1[0];
	       {
		    E Tb, T4, Tc, T7, Ta, T8, T9;
		    Tb = T2 + T3;
		    T4 = T2 - T3;
		    Tc = T5 + T6;
		    T7 = T5 - T6;
		    Ci[0] = -(KP951056516 * (FMA(KP618033988, Tc, Tb)));
		    Ci[WS(csi, 1)] = -(KP951056516 * (FNMS(KP618033988, Tb, Tc)));
		    Ta = T4 - T7;
		    T8 = T4 + T7;
		    T9 = FNMS(KP250000000, T8, T1);
		    Cr[WS(csr, 2)] = T1 + T8;
		    Cr[WS(csr, 1)] = FNMS(KP559016994, Ta, T9);
		    Cr[0] = FMA(KP559016994, Ta, T9);
	       }
	  }
     }
}

static const kr2c_desc desc = { 5, "r2cfII_5", {7, 2, 5, 0}, &GENUS };

void X(codelet_r2cfII_5) (planner *p) {
     X(kr2c_register) (p, r2cfII_5, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_r2cf.native -compact -variables 4 -pipeline-latency 4 -n 5 -name r2cfII_5 -dft-II -include r2cfII.h */

/*
 * This function contains 12 FP additions, 6 FP multiplications,
 * (or, 9 additions, 3 multiplications, 3 fused multiply/add),
 * 17 stack variables, 4 constants, and 10 memory accesses
 */
#include "r2cfII.h"

static void r2cfII_5(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP587785252, +0.587785252292473129168705954639072768597652438);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(20, rs), MAKE_VOLATILE_STRIDE(20, csr), MAKE_VOLATILE_STRIDE(20, csi)) {
	       E T8, T3, T6, T9, Tc, Tb, T7, Ta;
	       T8 = R0[0];
	       {
		    E T1, T2, T4, T5;
		    T1 = R0[WS(rs, 1)];
		    T2 = R1[WS(rs, 1)];
		    T3 = T1 - T2;
		    T4 = R0[WS(rs, 2)];
		    T5 = R1[0];
		    T6 = T4 - T5;
		    T9 = T3 + T6;
		    Tc = T4 + T5;
		    Tb = T1 + T2;
	       }
	       Cr[WS(csr, 2)] = T8 + T9;
	       Ci[WS(csi, 1)] = FNMS(KP951056516, Tc, KP587785252 * Tb);
	       Ci[0] = -(FMA(KP951056516, Tb, KP587785252 * Tc));
	       T7 = KP559016994 * (T3 - T6);
	       Ta = FNMS(KP250000000, T9, T8);
	       Cr[0] = T7 + Ta;
	       Cr[WS(csr, 1)] = Ta - T7;
	  }
     }
}

static const kr2c_desc desc = { 5, "r2cfII_5", {9, 3, 3, 0}, &GENUS };

void X(codelet_r2cfII_5) (planner *p) {
     X(kr2c_register) (p, r2cfII_5, &desc);
}

#endif				/* HAVE_FMA */
