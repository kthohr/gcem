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
 * compile-time error function
 */

#ifndef _gcem_erf_HPP
#define _gcem_erf_HPP

// see
// http://functions.wolfram.com/GammaBetaErf/Erf/10/01/0007/

template<typename T>
constexpr
T
erf_int_cf_large_recur(const T x, const int depth)
{
    return ( depth < GCEM_ERF_MAX_ITER ? x + 2*depth/erf_int_cf_large_recur(x,depth+1) : x );
}

template<typename T>
constexpr
T
erf_int_cf_large_main(const T x)
{
    return ( T(1.0) - T(2.0) * ( exp(-x*x) / T(GCEM_SQRT_PI) ) / erf_int_cf_large_recur(T(2.0)*x,1) );
}

// see
// http://functions.wolfram.com/GammaBetaErf/Erf/10/01/0005/

template<typename T>
constexpr
T
erf_int_cf_small_recur(const T xx, const int depth)
{
    return ( depth < GCEM_ERF_MAX_ITER ? (2*depth - 1) - 2*xx + 4*depth*xx/erf_int_cf_small_recur(xx,depth+1) : (2*depth - 1) - 2*xx );
}

template<typename T>
constexpr
T
erf_int_cf_small_main(const T x)
{
    return ( T(2.0) * x * ( exp(-x*x) / T(GCEM_SQRT_PI) ) / erf_int_cf_small_recur(x*x,1) );
}

//

template<typename T>
constexpr
T
erf_int(const T x)
{
    return ( x > T(2.1) ? erf_int_cf_large_main(x) : erf_int_cf_small_main(x) );
}

template<typename T>
constexpr
T
erf(const T x)
{
    return ( GCEM_LIM<T>::epsilon() > abs(x) ? T(0.0) : ( x < T(0.0) ? -erf_int(-x) : erf_int(x) ) );
}

#endif
