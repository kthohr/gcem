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
 * inverse of the incomplete beta function
 */

#ifndef _gcem_incomplete_beta_inv_HPP
#define _gcem_incomplete_beta_inv_HPP

constexpr long double incomplete_beta_inv_decision(const long double value, const long double alpha_par, const long double beta_par, const long double p, const long double direc, const long double lb_val, const int iter_count);

//
// initial value for Halley

//
// a,b > 1 case

constexpr
long double
incomplete_beta_inv_initial_val_1_tval(const long double p)
{ // a > 1.0
    return ( p > 0.5 ? sqrt(-2.0*log(1.0 - p)) : sqrt(-2.0*log(p)) );
}

constexpr
long double
incomplete_beta_inv_initial_val_1_int_begin(const long double t_val)
{ // internal for a > 1.0
    return ( t_val - (2.515517 + 0.802853*t_val + 0.010328*t_val*t_val)/(1.0 + 1.432788*t_val + 0.189269*t_val*t_val + 0.001308*t_val*t_val*t_val) );
}

constexpr
long double
incomplete_beta_inv_initial_val_1_int_ab1(const long double alpha_par, const long double beta_par)
{
    return ( 1.0/(2*alpha_par - 1.0) + 1.0/(2*beta_par - 1.0) );
}

constexpr
long double
incomplete_beta_inv_initial_val_1_int_ab2(const long double alpha_par, const long double beta_par)
{
    return ( 1.0/(2*beta_par - 1.0) - 1.0/(2*alpha_par - 1.0) );
}

// constexpr
// long double
// incomplete_beta_inv_initial_val_1_int_lambda(const long double value)
// {
//     return ( (value*value - 3.0)/6.0 );
// }

constexpr
long double
incomplete_beta_inv_initial_val_1_int_h(const long double ab_term_1)
{
    return ( 2.0 / ab_term_1 );
}

constexpr
long double
incomplete_beta_inv_initial_val_1_int_w(const long double value, const long double ab_term_2, const long double h_term)
{
    // return ( value * sqrt(h_term + lambda)/h_term - ab_term_2*(lambda + 5.0/6.0 -2.0/(3.0*h_term)) );
    return ( value * sqrt(h_term + (value*value - 3.0)/6.0)/h_term - ab_term_2*((value*value - 3.0)/6.0 + 5.0/6.0 -2.0/(3.0*h_term)) );
}

constexpr
long double
incomplete_beta_inv_initial_val_1_int_end(const long double alpha_par, const long double beta_par, const long double w_term)
{
    return ( alpha_par / (alpha_par + beta_par*exp(2.0*w_term)) );
}

constexpr
long double
incomplete_beta_inv_initial_val_1(const long double alpha_par, const long double beta_par, const long double p, const long double t_val)
{ // a > 1.0
    return ( p > 0.5 ? incomplete_beta_inv_initial_val_1_int_end( alpha_par, beta_par, incomplete_beta_inv_initial_val_1_int_w(-incomplete_beta_inv_initial_val_1_int_begin(t_val),incomplete_beta_inv_initial_val_1_int_ab2(alpha_par,beta_par),incomplete_beta_inv_initial_val_1_int_h(incomplete_beta_inv_initial_val_1_int_ab1(alpha_par,beta_par))) ) : 
                       incomplete_beta_inv_initial_val_1_int_end( alpha_par, beta_par, incomplete_beta_inv_initial_val_1_int_w(-incomplete_beta_inv_initial_val_1_int_begin(t_val),incomplete_beta_inv_initial_val_1_int_ab2(alpha_par,beta_par),incomplete_beta_inv_initial_val_1_int_h(incomplete_beta_inv_initial_val_1_int_ab1(alpha_par,beta_par))) ) );
}

//
// a,b else

constexpr
long double
incomplete_beta_inv_initial_val_2_s1(const long double alpha_par, const long double beta_par)
{
    return ( pow_dbl(alpha_par/(alpha_par+beta_par),alpha_par) / alpha_par );
}

constexpr
long double
incomplete_beta_inv_initial_val_2_s2(const long double alpha_par, const long double beta_par)
{
    return ( pow_dbl(beta_par/(alpha_par+beta_par),beta_par) / beta_par );
}

constexpr
long double
incomplete_beta_inv_initial_val_2(const long double alpha_par, const long double beta_par, const long double p, const long double s_1, const long double s_2)
{
    return ( p <= s_1/(s_1+s_2) ? pow_dbl(p*(s_1+s_2)*alpha_par,1.0/alpha_par) : 1.0 - pow_dbl(p*(s_1+s_2)*beta_par,1.0/beta_par) );
}

// initial value

constexpr
long double
incomplete_beta_inv_initial_val(const long double alpha_par, const long double beta_par, const long double p)
{
    return ( (alpha_par > 1.0 && beta_par > 1.0) ? incomplete_beta_inv_initial_val_1(alpha_par,beta_par,p,incomplete_beta_inv_initial_val_1_tval(p)) : 
                                                   incomplete_beta_inv_initial_val_2(alpha_par,beta_par,p,incomplete_beta_inv_initial_val_2_s1(alpha_par,beta_par),incomplete_beta_inv_initial_val_2_s2(alpha_par,beta_par)) );
}

//
// Halley recursion

constexpr
long double
incomplete_beta_inv_err_val(const long double value, const long double alpha_par, const long double beta_par, const long double p)
{ // err_val = f(x)
    return ( incomplete_beta(alpha_par,beta_par,value) - p );
}

constexpr
long double
incomplete_beta_inv_deriv_1(const long double value, const long double alpha_par, const long double beta_par, const long double lb_val)
{ // derivative of the incomplete beta function w.r.t. x
    return ( exp( (alpha_par-1.0)*log(value) + (beta_par-1.0)*log(1.0 - value) - lb_val ) );
}

constexpr
long double
incomplete_beta_inv_deriv_2(const long double value, const long double alpha_par, const long double beta_par, const long double deriv_1)
{ // second derivative of the incomplete beta function w.r.t. x
    return ( deriv_1*((alpha_par - 1.0)/value - (beta_par - 1.0)/(1.0 - value)) );
}

constexpr
long double
incomplete_beta_inv_ratio_val_1(const long double value, const long double alpha_par, const long double beta_par, const long double p, const long double deriv_1)
{
    return ( incomplete_beta_inv_err_val(value,alpha_par,beta_par,p) / deriv_1 );
}

constexpr
long double
incomplete_beta_inv_ratio_val_2(const long double value, const long double alpha_par, const long double beta_par, const long double p, const long double deriv_1)
{
    return ( incomplete_beta_inv_deriv_2(value,alpha_par,beta_par,deriv_1) / deriv_1 );
}

constexpr
long double
incomplete_beta_inv_halley(const long double ratio_val_1, const long double ratio_val_2)
{
    return ( ratio_val_1 / max( 0.8L, min( 1.2L, 1.0 - 0.5*ratio_val_1*ratio_val_2 ) ) );
}

constexpr
long double
incomplete_beta_inv_recur(const long double value, const long double alpha_par, const long double beta_par, const long double p, const long double deriv_1, const long double lb_val, const int iter_count)
{
    return ( incomplete_beta_inv_decision( value, alpha_par, beta_par, p, incomplete_beta_inv_halley(incomplete_beta_inv_ratio_val_1(value,alpha_par,beta_par,p,deriv_1),incomplete_beta_inv_ratio_val_2(value,alpha_par,beta_par,p,deriv_1)), lb_val, iter_count ) );
}

constexpr
long double
incomplete_beta_inv_decision(const long double value, const long double alpha_par, const long double beta_par, const long double p, const long double direc, const long double lb_val, const int iter_count)
{
    return ( iter_count <= GCEM_INCML_BETA_INV_MAX_ITER ? incomplete_beta_inv_recur(value-direc,alpha_par,beta_par,p, incomplete_beta_inv_deriv_1(value,alpha_par,beta_par,lb_val), lb_val, iter_count+1) : value - direc );
}

constexpr
long double
incomplete_beta_inv_int(const long double initial_val, const long double alpha_par, const long double beta_par, const long double p, const long double lb_val)
{
    return ( incomplete_beta_inv_recur(initial_val,alpha_par,beta_par,p,incomplete_beta_inv_deriv_1(initial_val,alpha_par,beta_par,lb_val),lb_val,1) );
}

constexpr
long double
incomplete_beta_inv(const long double alpha_par, const long double beta_par, const long double p)
{
    return ( incomplete_beta_inv_int(incomplete_beta_inv_initial_val(alpha_par,beta_par,p),alpha_par,beta_par,p,lbeta(alpha_par,beta_par)) );
}

#endif
