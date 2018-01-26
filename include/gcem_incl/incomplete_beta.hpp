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
 * compile-time incomplete beta function
 *
 * see eq. 18.5.17a in the Handbook of Continued Fractions for Special Functions
 */

#ifndef _gcem_incomplete_beta_HPP
#define _gcem_incomplete_beta_HPP

template<typename T>
constexpr T incomplete_beta_cf(const T a, const T b, const T z, const T c_j, const T d_j, const T f_j, const int depth);

//
// coefficients; see eq. 18.5.17b

template<typename T>
constexpr
T
incomplete_beta_coef_even(const T a, const T b, const T z, const int k)
{
    return ( -z*(a + k)*(a + b + k)/( (a + 2*k)*(a + 2*k + T(1.0)) ) );
}

template<typename T>
constexpr
T
incomplete_beta_coef_odd(const T a, const T b, const T z, const int k)
{
    return ( z*k*(b - k)/((a + 2*k - T(1.0))*(a + 2*k)) );
}

template<typename T>
constexpr
T
incomplete_beta_coef(const T a, const T b, const T z, const int depth)
{
    return ( is_odd(depth) == 0 ? incomplete_beta_coef_even(a,b,z,depth/2) : incomplete_beta_coef_odd(a,b,z,(depth+1)/2) );
}

//
// update formulae for the modified Lentz method

template<typename T>
constexpr
T
incomplete_beta_c_update(const T a, const T b, const T z, const T c_j, const int depth)
{
    return ( T(1.0) + incomplete_beta_coef(a,b,z,depth)/c_j );
}

template<typename T>
constexpr
T
incomplete_beta_d_update(const T a, const T b, const T z, const T d_j, const int depth)
{
    return ( T(1.0) / (T(1.0) + incomplete_beta_coef(a,b,z,depth)*d_j) );
}

//
// convergence-type condition

template<typename T>
constexpr
T
incomplete_beta_decision(const T a, const T b, const T z, const T c_j, const T d_j, const T f_j, const int depth)
{
    return ( abs(c_j*d_j - T(1.0)) < GCEM_INCML_BETA_TOL ? f_j*c_j*d_j : ( depth < GCEM_INCML_BETA_MAX_ITER ? incomplete_beta_cf(a,b,z,c_j,d_j,f_j*c_j*d_j,depth+1) : f_j*c_j*d_j ) );
}

template<typename T>
constexpr
T
incomplete_beta_cf(const T a, const T b, const T z, const T c_j, const T d_j, const T f_j, const int depth)
{
    return ( incomplete_beta_decision(a,b,z,incomplete_beta_c_update(a,b,z,c_j,depth),incomplete_beta_d_update(a,b,z,d_j,depth),f_j,depth) );
}

//
// x^a (1-x)^{b} / (a beta(a,b)) * cf

template<typename T>
constexpr
T
incomplete_beta_int(const T a, const T b, const T z)
{
    return ( (exp(a*log(z) + b*log(T(1.0)-z) - lbeta(a,b)) / a) * incomplete_beta_cf(a,b,z,T(1.0),incomplete_beta_d_update(a,b,z,T(1.0),0),incomplete_beta_d_update(a,b,z,T(1.0),0),1) );
}

template<typename T>
constexpr
T
incomplete_beta(const T a, const T b, const T z)
{
    return ( z == T(0.0) ? T(0.0) : ( z < (a + T(1.0))/(a + b + T(2.0)) ? incomplete_beta_int(a,b,z) : T(1.0) - incomplete_beta_int(b,a,T(1.0) - z) ) );
}

#endif
