/*################################################################################
  ##
  ##   Copyright (C) 2016-2017 Keith O'Hara
  ##
  ##   This file is part of the GCE-Math C++ library.
  ##
  ##   GCE-Math is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   GCE-Math is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

/* 
 * compile-time inverse error function
 *
 * Based on:
 * 'Approximating the erfinv function' by Mike Giles
 *
 * Keith O'Hara
 * 06/15/2016
 *
 * This version:
 * 07/01/2017
 */

#ifndef _gcem_erfinv_HPP
#define _gcem_erfinv_HPP

//
// two cases: (1) a < 5; and (2) otherwise

constexpr
long double
erfinv_coef_2(const long double a, const long double p_term, const int order)
{
    return ( order == 1 ? -0.000200214257L : 
             order == 2 ?  0.000100950558L + a*p_term : order == 3 ?  0.00134934322L + a*p_term : order == 4 ? -0.003673428440L + a*p_term : 
             order == 5 ?  0.005739507730L + a*p_term : order == 6 ? -0.00762246130L + a*p_term : order == 7 ?  0.009438870470L + a*p_term :
             order == 8 ?  1.001674060000L + a*p_term : order == 9 ?  2.83297682000L + a*p_term : p_term );
}


constexpr
long double
erfinv_case_2(const long double a, const long double p_term, const int order)
{
    return ( order == 9 ? erfinv_coef_2(a,p_term,order) : erfinv_case_2(a,erfinv_coef_2(a,p_term,order),order+1) );
}

constexpr
long double
erfinv_coef_1(const long double a, const long double p_term, const int order)
{
    return ( order == 1 ?  2.81022636e-08L : 
             order == 2 ?  3.43273939e-07L + a*p_term : order == 3 ? -3.5233877e-06L + a*p_term : 
             order == 4 ? -4.39150654e-06L + a*p_term : order == 5 ?  0.00021858087L + a*p_term : order == 6 ? -0.00125372503L + a*p_term : 
             order == 7 ? -0.004177681640L + a*p_term : order == 8 ?  0.24664072700L + a*p_term : order == 9 ?  1.50140941000L + a*p_term : p_term );
}


constexpr
long double
erfinv_case_1(const long double a, const long double p_term, const int order)
{
    return ( order == 9 ? erfinv_coef_1(a,p_term,order) : erfinv_case_1(a,erfinv_coef_1(a,p_term,order),order+1) );
}

constexpr
long double
erfinv_int(const long double a)
{
    return ( a < 5.0 ? erfinv_case_1(a-2.5,0.0,1) : erfinv_case_2(sqrt(a)-3.0,0.0,1) );
}

constexpr
long double
erfinv(const long double x)
{
    return x*erfinv_int( -log( (1.0 - x)*(1.0 + x) ) );
}

#endif
