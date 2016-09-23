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
/* Generated on Tue Mar  4 13:50:41 EST 2014 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_hc2c.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -twiddle-log3 -precompute-twiddles -n 4 -dif -name hc2cb2_4 -include hc2cb.h */

/*
 * This function contains 24 FP additions, 16 FP multiplications,
 * (or, 16 additions, 8 multiplications, 8 fused multiply/add),
 * 30 stack variables, 0 constants, and 16 memory accesses
 */
#include "hc2cb.h"

static void hc2cb2_4(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 4); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 4, MAKE_VOLATILE_STRIDE(16, rs)) {
	       E Tg, Tc, Te, To, Tn;
	       {
		    E T7, Tb, T8, Ta;
		    T7 = W[0];
		    Tb = W[3];
		    T8 = W[2];
		    Ta = W[1];
		    {
			 E Tu, Tj, T3, Tm, Tx, Tr, T6, Tt;
			 {
			      E T4, Tp, Tq, T5;
			      {
				   E T1, T2, Tk, Tl;
				   {
					E Th, Tf, T9, Ti;
					Th = Ip[0];
					Tf = T7 * Tb;
					T9 = T7 * T8;
					Ti = Im[WS(rs, 1)];
					T1 = Rp[0];
					Tg = FNMS(Ta, T8, Tf);
					Tc = FMA(Ta, Tb, T9);
					Tu = Th + Ti;
					Tj = Th - Ti;
					T2 = Rm[WS(rs, 1)];
				   }
				   Tk = Ip[WS(rs, 1)];
				   Tl = Im[0];
				   T4 = Rp[WS(rs, 1)];
				   T3 = T1 + T2;
				   Tp = T1 - T2;
				   Tm = Tk - Tl;
				   Tq = Tk + Tl;
				   T5 = Rm[0];
			      }
			      Tx = Tp + Tq;
			      Tr = Tp - Tq;
			      T6 = T4 + T5;
			      Tt = T4 - T5;
			 }
			 {
			      E Tz, Tv, Td, Ts, Tw, TA, Ty;
			      Rm[0] = Tj + Tm;
			      Ts = T7 * Tr;
			      Tz = Tu - Tt;
			      Tv = Tt + Tu;
			      Rp[0] = T3 + T6;
			      Td = T3 - T6;
			      Ip[0] = FNMS(Ta, Tv, Ts);
			      Tw = T7 * Tv;
			      TA = T8 * Tz;
			      Ty = T8 * Tx;
			      Te = Tc * Td;
			      Im[0] = FMA(Ta, Tr, Tw);
			      Im[WS(rs, 1)] = FMA(Tb, Tx, TA);
			      Ip[WS(rs, 1)] = FNMS(Tb, Tz, Ty);
			      To = Tg * Td;
			      Tn = Tj - Tm;
			 }
		    }
	       }
	       Rm[WS(rs, 1)] = FMA(Tc, Tn, To);
	       Rp[WS(rs, 1)] = FNMS(Tg, Tn, Te);
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_CEXP, 1, 1},
     {TW_CEXP, 1, 3},
     {TW_NEXT, 1, 0}
};

static const hc2c_desc desc = { 4, "hc2cb2_4", twinstr, &GENUS, {16, 8, 8, 0} };

void X(codelet_hc2cb2_4) (planner *p) {
     X(khc2c_register) (p, hc2cb2_4, &desc, HC2C_VIA_RDFT);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_hc2c.native -compact -variables 4 -pipeline-latency 4 -sign 1 -twiddle-log3 -precompute-twiddles -n 4 -dif -name hc2cb2_4 -include hc2cb.h */

/*
 * This function contains 24 FP additions, 16 FP multiplications,
 * (or, 16 additions, 8 multiplications, 8 fused multiply/add),
 * 21 stack variables, 0 constants, and 16 memory accesses
 */
#include "hc2cb.h"

static void hc2cb2_4(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 4); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 4, MAKE_VOLATILE_STRIDE(16, rs)) {
	       E T7, T9, T8, Ta, Tb, Td;
	       T7 = W[0];
	       T9 = W[1];
	       T8 = W[2];
	       Ta = W[3];
	       Tb = FMA(T7, T8, T9 * Ta);
	       Td = FNMS(T9, T8, T7 * Ta);
	       {
		    E T3, Tl, Tg, Tp, T6, To, Tj, Tm, Tc, Tk;
		    {
			 E T1, T2, Te, Tf;
			 T1 = Rp[0];
			 T2 = Rm[WS(rs, 1)];
			 T3 = T1 + T2;
			 Tl = T1 - T2;
			 Te = Ip[0];
			 Tf = Im[WS(rs, 1)];
			 Tg = Te - Tf;
			 Tp = Te + Tf;
		    }
		    {
			 E T4, T5, Th, Ti;
			 T4 = Rp[WS(rs, 1)];
			 T5 = Rm[0];
			 T6 = T4 + T5;
			 To = T4 - T5;
			 Th = Ip[WS(rs, 1)];
			 Ti = Im[0];
			 Tj = Th - Ti;
			 Tm = Th + Ti;
		    }
		    Rp[0] = T3 + T6;
		    Rm[0] = Tg + Tj;
		    Tc = T3 - T6;
		    Tk = Tg - Tj;
		    Rp[WS(rs, 1)] = FNMS(Td, Tk, Tb * Tc);
		    Rm[WS(rs, 1)] = FMA(Td, Tc, Tb * Tk);
		    {
			 E Tn, Tq, Tr, Ts;
			 Tn = Tl - Tm;
			 Tq = To + Tp;
			 Ip[0] = FNMS(T9, Tq, T7 * Tn);
			 Im[0] = FMA(T7, Tq, T9 * Tn);
			 Tr = Tl + Tm;
			 Ts = Tp - To;
			 Ip[WS(rs, 1)] = FNMS(Ta, Ts, T8 * Tr);
			 Im[WS(rs, 1)] = FMA(T8, Ts, Ta * Tr);
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_CEXP, 1, 1},
     {TW_CEXP, 1, 3},
     {TW_NEXT, 1, 0}
};

static const hc2c_desc desc = { 4, "hc2cb2_4", twinstr, &GENUS, {16, 8, 8, 0} };

void X(codelet_hc2cb2_4) (planner *p) {
     X(khc2c_register) (p, hc2cb2_4, &desc, HC2C_VIA_RDFT);
}
#endif				/* HAVE_FMA */