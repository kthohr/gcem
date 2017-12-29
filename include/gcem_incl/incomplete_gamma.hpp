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
 * compile-time (regularized) incomplete gamma function
 */

#ifndef _gcem_incomplete_gamma_HPP
#define _gcem_incomplete_gamma_HPP

// for the expansion, see:
// http://functions.wolfram.com/GammaBetaErf/Gamma2/10/0009/

template<typename T>
constexpr
T
incomplete_gamma_cf_coef(const T a, const T z, const int depth)
{
    return ( is_odd(depth) == 1 ? - T(a-1+(depth+1)/2.0) * z : T(depth/2.0) * z );
}

template<typename T>
constexpr
T
incomplete_gamma_cf_int(const T a, const T z, const int depth)
{
    return ( depth < GCEM_INCML_GAMMA_MAX_ITER ? (a + depth - 1) + incomplete_gamma_cf_coef(a,z,depth)/incomplete_gamma_cf_int(a,z,depth+1) : (a + depth - 1) );
}

template<typename T>
constexpr
T
incomplete_gamma_int(const T a, const T z)
{ // lower (regularized) incomplete gamma function
    return ( exp(a*log(z) - z) / tgamma(a) / incomplete_gamma_cf_int(a,z,1) );
}

template<typename T>
constexpr
T
incomplete_gamma(const T a, const T z)
{
    return ( GCEM_LIM<T>::epsilon() > z ? T(0.0) : GCEM_LIM<T>::epsilon() > a ? T(1.0) : z <= T(0.0) ? T(0.0) : incomplete_gamma_int(a,z) );
}

#endif
