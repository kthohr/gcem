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
 * compile-time incomplete beta function
 *
 * see eq. 18.5.17a in the Handbook of Continued Fractions for Special Functions
 *
 * Keith O'Hara
 * 06/18/2016
 *
 * This version:
 * 07/01/2017
 */

#ifndef _gcem_incomplete_beta_HPP
#define _gcem_incomplete_beta_HPP

constexpr long double incomplete_beta_cf(const long double a, const long double b, const long double z, const long double c_j, const long double d_j, const long double f_j, const int depth);

//
// coefficients; see eq. 18.5.17b

constexpr
long double
incomplete_beta_coef_even(const long double a, const long double b, const long double z, const int k)
{
    return ( -z*(a + k)*(a + b + k)/( (a + 2*k)*(a + 2*k + 1.0) ) );
}

constexpr
long double
incomplete_beta_coef_odd(const long double a, const long double b, const long double z, const int k)
{
    return ( z*k*(b - k)/((a + 2*k - 1.0)*(a + 2*k)) );
}

constexpr
long double
incomplete_beta_coef(const long double a, const long double b, const long double z, const int depth)
{
    return ( is_odd(depth) == 0 ? incomplete_beta_coef_even(a,b,z,depth/2) : incomplete_beta_coef_odd(a,b,z,(depth+1)/2) );
}

//
// update formulae for the modified Lentz method

constexpr
long double
incomplete_beta_c_update(const long double a, const long double b, const long double z, const long double c_j, const int depth)
{
    return ( 1.0L + incomplete_beta_coef(a,b,z,depth)/c_j );
}

constexpr
long double
incomplete_beta_d_update(const long double a, const long double b, const long double z, const long double d_j, const int depth)
{
    return ( 1.0L / (1.0L + incomplete_beta_coef(a,b,z,depth)*d_j) );
}

//
// convergence-type condition

constexpr
long double
incomplete_beta_decision(const long double a, const long double b, const long double z, const long double c_j, const long double d_j, const long double f_j, const int depth)
{
    return ( abs(c_j*d_j - 1.0L) < GCEM_INCML_BETA_TOL ? f_j*c_j*d_j : ( depth < GCEM_INCML_BETA_MAX_ITER ? incomplete_beta_cf(a,b,z,c_j,d_j,f_j*c_j*d_j,depth+1) : f_j*c_j*d_j ) );
}

constexpr
long double
incomplete_beta_cf(const long double a, const long double b, const long double z, const long double c_j, const long double d_j, const long double f_j, const int depth)
{
    return ( incomplete_beta_decision(a,b,z,incomplete_beta_c_update(a,b,z,c_j,depth),incomplete_beta_d_update(a,b,z,d_j,depth),f_j,depth) );
}

//
// x^a (1-x)^{b} / (a beta(a,b)) * cf

constexpr
long double
incomplete_beta_int(const long double a, const long double b, const long double z)
{
    return ( (exp(a*log(z) + b*log(1.0-z) - lbeta(a,b)) / a) * incomplete_beta_cf(a,b,z,1.0,incomplete_beta_d_update(a,b,z,1.0,0),incomplete_beta_d_update(a,b,z,1.0,0),1) );
}

constexpr
long double
incomplete_beta(const long double a, const long double b, const long double z)
{
    return ( z == 0 ? 0 : ( z < (a+1)/(a+b+2) ? incomplete_beta_int(a,b,z) : 1 - incomplete_beta_int(b,a,1 - z) ) );
}

// Below is a modified version of ASA063 by John Burkardt

// inline
// bool
// incomplete_beta(double alpha_par, double beta_par, double x, double& ret) // beta(x;alpha_par,beta_par)
// {
//     bool success = false;
//     //
//     //  Check the input.
//     if (alpha_par <= 0.0 || beta_par <= 0.0) {
//         ret = 0.0;
//         return false;
//     }

//     if (x <= 0.0) {
//         ret = 0.0;
//         return false;
//     }

//     if (1.0 <= x) {
//         ret = 1.0;
//         return false;
//     }

//     double acu = 1.0E-14;
//     double lbeta = std::lgamma(alpha_par) + std::lgamma(beta_par) - std::lgamma(alpha_par + beta_par); // log beta function value
//     //
//     //  Change tail if necessary and determine S.
//     //
//     double ab_par = alpha_par + beta_par;
//     double cx = 1.0 - x;

//     bool indx;
//     double alpha_par_use, beta_par_use, xx;

//     if (alpha_par < ab_par * x) {
//         xx = cx;
//         cx = x;
//         alpha_par_use = beta_par;
//         beta_par_use = alpha_par;
//         indx = true;
//     } else {
//         xx = x;
//         alpha_par_use = alpha_par;
//         beta_par_use = beta_par;
//         indx = false;
//     }

//     int ns = ( int ) ( beta_par_use + cx * ab_par );
//     //
//     //  Use the Soper reduction formula.
//     //
//     double rx = xx / cx;
//     if (ns == 0) {
//         rx = xx;
//     }

//     double term = 1.0, ai = 1.0, value = 1.0;
//     double temp = beta_par_use - ai;

//     while (1) {
//         term *= temp * rx / ( alpha_par_use + ai );
//         value += term;
//         temp = std::abs(term);

//         if (temp <= acu && temp <= acu * value) {
//             value = value * std::exp( alpha_par_use*std::log(xx) + (beta_par_use - 1.0)*std::log(cx) - lbeta ) / alpha_par_use;

//             if (indx) {
//                 value = 1.0 - value;
//             }

//             success = true;
//             break;
//         }

//         ai += 1.0;
//         ns--;

//         if (0 <= ns) {
//             temp = beta_par_use - ai;
//             if (ns == 0) {
//                 rx = xx;
//             }
//         } else {
//             temp = ab_par;
//             ab_par += 1.0;
//         }
//     }
//     //
//     ret = value;
//     //
//     return success;
// }

#endif
