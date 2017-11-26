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
 * inverse of the incomplete gamma function
 */

#ifndef _gcem_incomplete_gamma_inv_HPP
#define _gcem_incomplete_gamma_inv_HPP


#define GCEM_INCML_GAMMA_INV_TOL 1e-08

constexpr long double incomplete_gamma_inv_decision(const long double value, const long double a, const long double p, const long double direc, const long double lg_val, const int iter_count);

//
// initial value for Halley

constexpr
long double
incomplete_gamma_inv_t_val_1(const long double p)
{ // a > 1.0
    return ( p > 0.5L ? sqrt(-2.0*log(1.0 - p)) : sqrt(-2.0*log(p)) );
}

constexpr
long double
incomplete_gamma_inv_t_val_2(const long double a)
{ // a <= 1.0
    return ( 1.0L - 0.253L * a - 0.12L * a*a );
}

//

constexpr
long double
incomplete_gamma_inv_initial_val_1_int_begin(const long double t_val)
{ // internal for a > 1.0
    return ( t_val - (2.515517L + 0.802853L*t_val + 0.010328L*t_val*t_val)/(1.0L + 1.432788L*t_val + 0.189269L*t_val*t_val + 0.001308L*t_val*t_val*t_val) );
}

constexpr
long double
incomplete_gamma_inv_initial_val_1_int_end(const long double value_inp, const long double a)
{ // internal for a > 1.0
    return ( max( 1E-04L, a*pow(1.0 - 1.0/(9.0*a) - value_inp/(3.0*sqrt(a)),3) ) );
}

constexpr
long double
incomplete_gamma_inv_initial_val_1(const long double a, const long double p, const long double t_val)
{ // a > 1.0
    return ( p > 0.5L ? incomplete_gamma_inv_initial_val_1_int_end(-incomplete_gamma_inv_initial_val_1_int_begin(t_val), a) : incomplete_gamma_inv_initial_val_1_int_end(incomplete_gamma_inv_initial_val_1_int_begin(t_val), a) );
}

constexpr
long double
incomplete_gamma_inv_initial_val_2(const long double a, const long double p, const long double t_val)
{ // a <= 1.0
    return ( p < t_val ? pow_dbl(p/t_val,1.0L/a) : 1.0L - log(1.0L - (p - t_val)/(1.0L - t_val)) );
}

// initial value

constexpr
long double
incomplete_gamma_inv_initial_val(const long double a, const long double p)
{
    return ( a > 1.0 ? incomplete_gamma_inv_initial_val_1(a,p,incomplete_gamma_inv_t_val_1(p)) : incomplete_gamma_inv_initial_val_2(a,p,incomplete_gamma_inv_t_val_2(a)) );
}

//
// Halley recursion

constexpr
long double
incomplete_gamma_inv_err_val(const long double value, const long double a, const long double p)
{ // err_val = f(x)
    return ( incomplete_gamma(a,value) - p );
}

constexpr
long double
incomplete_gamma_inv_deriv_1(const long double value, const long double a, const long double lg_val)
{ // derivative of the incomplete gamma function w.r.t. x
    return ( exp( - value + (a - 1.0L)*log(value) - lg_val ) );
}

constexpr
long double
incomplete_gamma_inv_deriv_2(const long double value, const long double a, const long double deriv_1)
{ // second derivative of the incomplete gamma function w.r.t. x
    return ( deriv_1*((a - 1.0L)/value - 1.0L) );
}

constexpr
long double
incomplete_gamma_inv_ratio_val_1(const long double value, const long double a, const long double p, const long double deriv_1)
{
    return ( incomplete_gamma_inv_err_val(value,a,p) / deriv_1 );
}

constexpr
long double
incomplete_gamma_inv_ratio_val_2(const long double value, const long double a, const long double p, const long double deriv_1)
{
    return ( incomplete_gamma_inv_deriv_2(value,a,deriv_1) / deriv_1 );
}

constexpr
long double
incomplete_gamma_inv_halley(const long double ratio_val_1, const long double ratio_val_2)
{
    return ( ratio_val_1 / max( 0.8L, min( 1.2L, 1.0L - 0.5L*ratio_val_1*ratio_val_2 ) ) );
}

constexpr
long double
incomplete_gamma_inv_recur(const long double value, const long double a, const long double p, const long double deriv_1, const long double lg_val, const int iter_count)
{
    return ( incomplete_gamma_inv_decision( value, a, p, incomplete_gamma_inv_halley(incomplete_gamma_inv_ratio_val_1(value,a,p,deriv_1),incomplete_gamma_inv_ratio_val_2(value,a,p,deriv_1)), lg_val, iter_count ) );
}

constexpr
long double
incomplete_gamma_inv_decision(const long double value, const long double a, const long double p, const long double direc, const long double lg_val, const int iter_count)
{
    // return ( abs(direc) > GCEM_INCML_GAMMA_INV_TOL ? incomplete_gamma_inv_recur(value - direc, a, p, incomplete_gamma_inv_deriv_1(value,a,lg_val), lg_val) : value - direc );
    return ( iter_count <= GCEM_INCML_GAMMA_INV_MAX_ITER ? incomplete_gamma_inv_recur(value-direc,a,p, incomplete_gamma_inv_deriv_1(value,a,lg_val), lg_val, iter_count+1) : value - direc );
}

constexpr
long double
incomplete_gamma_inv_int(const long double initial_val, const long double a, const long double p, const long double lg_val)
{
    return ( incomplete_gamma_inv_recur(initial_val,a,p,incomplete_gamma_inv_deriv_1(initial_val,a,lg_val),lg_val,1) );
}

constexpr
long double
incomplete_gamma_inv(const long double a, const long double p)
{
    return ( incomplete_gamma_inv_int(incomplete_gamma_inv_initial_val(a,p),a,p,lgamma(a)) );
}

#endif
