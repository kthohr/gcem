/*################################################################################
  ##
  ##   Copyright (C) 2016-2018 Keith O'Hara
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

// #define GCEM_INCML_GAMMA_INV_TOL 1e-08

template<typename T>
constexpr T incomplete_gamma_inv_decision(const T value, const T a, const T p, const T direc, const T lg_val, const int iter_count);

//
// initial value for Halley

template<typename T>
constexpr
T
incomplete_gamma_inv_t_val_1(const T p)
{ // a > 1.0
    return ( p > T(0.5) ? sqrt(-2*log(T(1.0) - p)) : sqrt(-2*log(p)) );
}

template<typename T>
constexpr
T
incomplete_gamma_inv_t_val_2(const T a)
{ // a <= 1.0
    return ( T(1.0) - T(0.253) * a - T(0.12) * a*a );
}

//

template<typename T>
constexpr
T
incomplete_gamma_inv_initial_val_1_int_begin(const T t_val)
{ // internal for a > 1.0
    return ( t_val - (T(2.515517L) + T(0.802853L)*t_val + T(0.010328L)*t_val*t_val)/(T(1.0) + T(1.432788L)*t_val + T(0.189269L)*t_val*t_val + T(0.001308L)*t_val*t_val*t_val) );
}

template<typename T>
constexpr
T
incomplete_gamma_inv_initial_val_1_int_end(const T value_inp, const T a)
{ // internal for a > 1.0
    return max( T(1E-04), a*pow(T(1.0) - T(1.0)/(9*a) - value_inp/(3*sqrt(a)), 3) );
}

template<typename T>
constexpr
T
incomplete_gamma_inv_initial_val_1(const T a, const T p, const T t_val)
{ // a > 1.0
    return ( p > T(0.5) ? incomplete_gamma_inv_initial_val_1_int_end(-incomplete_gamma_inv_initial_val_1_int_begin(t_val), a) : incomplete_gamma_inv_initial_val_1_int_end(incomplete_gamma_inv_initial_val_1_int_begin(t_val), a) );
}

template<typename T>
constexpr
T
incomplete_gamma_inv_initial_val_2(const T a, const T p, const T t_val)
{ // a <= 1.0
    return ( p < t_val ? pow_dbl(p/t_val,T(1.0)/a) : T(1.0) - log(T(1.0) - (p - t_val)/(T(1.0) - t_val)) );
}

// initial value

template<typename T>
constexpr
T
incomplete_gamma_inv_initial_val(const T a, const T p)
{
    return ( a > T(1.0) ? incomplete_gamma_inv_initial_val_1(a,p,incomplete_gamma_inv_t_val_1(p)) : incomplete_gamma_inv_initial_val_2(a,p,incomplete_gamma_inv_t_val_2(a)) );
}

//
// Halley recursion

template<typename T>
constexpr
T
incomplete_gamma_inv_err_val(const T value, const T a, const T p)
{ // err_val = f(x)
    return ( incomplete_gamma(a,value) - p );
}

template<typename T>
constexpr
T
incomplete_gamma_inv_deriv_1(const T value, const T a, const T lg_val)
{ // derivative of the incomplete gamma function w.r.t. x
    return ( exp( - value + (a - T(1.0))*log(value) - lg_val ) );
}

template<typename T>
constexpr
T
incomplete_gamma_inv_deriv_2(const T value, const T a, const T deriv_1)
{ // second derivative of the incomplete gamma function w.r.t. x
    return ( deriv_1*((a - T(1.0))/value - T(1.0)) );
}

template<typename T>
constexpr
T
incomplete_gamma_inv_ratio_val_1(const T value, const T a, const T p, const T deriv_1)
{
    return ( incomplete_gamma_inv_err_val(value,a,p) / deriv_1 );
}

template<typename T>
constexpr
T
incomplete_gamma_inv_ratio_val_2(const T value, const T a, const T p, const T deriv_1)
{
    return ( incomplete_gamma_inv_deriv_2(value,a,deriv_1) / deriv_1 );
}

template<typename T>
constexpr
T
incomplete_gamma_inv_halley(const T ratio_val_1, const T ratio_val_2)
{
    return ( ratio_val_1 / max( T(0.8), min( T(1.2), T(1.0) - T(0.5)*ratio_val_1*ratio_val_2 ) ) );
}

template<typename T>
constexpr
T
incomplete_gamma_inv_recur(const T value, const T a, const T p, const T deriv_1, const T lg_val, const int iter_count)
{
    return ( incomplete_gamma_inv_decision( value, a, p, incomplete_gamma_inv_halley(incomplete_gamma_inv_ratio_val_1(value,a,p,deriv_1),incomplete_gamma_inv_ratio_val_2(value,a,p,deriv_1)), lg_val, iter_count ) );
}

template<typename T>
constexpr
T
incomplete_gamma_inv_decision(const T value, const T a, const T p, const T direc, const T lg_val, const int iter_count)
{
    // return ( abs(direc) > GCEM_INCML_GAMMA_INV_TOL ? incomplete_gamma_inv_recur(value - direc, a, p, incomplete_gamma_inv_deriv_1(value,a,lg_val), lg_val) : value - direc );
    return ( iter_count <= GCEM_INCML_GAMMA_INV_MAX_ITER ? incomplete_gamma_inv_recur(value-direc,a,p, incomplete_gamma_inv_deriv_1(value,a,lg_val), lg_val, iter_count+1) : value - direc );
}

template<typename T>
constexpr
T
incomplete_gamma_inv_int(const T initial_val, const T a, const T p, const T lg_val)
{
    return ( incomplete_gamma_inv_recur(initial_val,a,p,incomplete_gamma_inv_deriv_1(initial_val,a,lg_val),lg_val,1) );
}

template<typename T>
constexpr
T
incomplete_gamma_inv(const T a, const T p)
{
    return ( incomplete_gamma_inv_int(incomplete_gamma_inv_initial_val(a,p),a,p,lgamma(a)) );
}

#endif
