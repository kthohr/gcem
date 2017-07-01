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
 * compile-time error function
 *
 * Keith O'Hara
 * 06/25/2017
 *
 * This version:
 * 07/01/2017
 */

#ifndef _gcem_erf_HPP
#define _gcem_erf_HPP

constexpr
long double
erf_cf_int(const long double xx, const int depth)
{
    return ( depth == 35 ? (2*depth - 1) - 2*xx : (2*depth - 1) - 2*xx + 4*depth*xx/erf_cf_int(xx,depth+1) );
}

constexpr
long double
erf_cf(const long double x)
{
    return ( 2*x*(exp(-x*x)/GCEM_SQRT_PI) / erf_cf_int(x*x,1) );
}

constexpr
long double
erf(const long double x)
{
    return ( x == 0 ? 0 : ( x > 0 ? erf_cf(x) : -erf_cf(-x) ) );
}

// the expansion above seems to possess better approximation properties than the others below

// constexpr
// double
// erf_int(const double x, const double t)
// { // eq 7.1.26
//     return 1.0 - ( 0.254829592*t - 0.284496736*t*t + 1.421413741*t*t*t - 1.453152027*t*t*t*t + 1.061405429*t*t*t*t*t )*exp(-x*x);
// }

// constexpr
// double
// erf(const double x)
// {
//     return ( x == 0 ? 0 : ( x > 0 ? erf_int(x,1.0/(1+0.3275911*x)) : -erf_int(-x,1.0/(1-0.3275911*x)) ) );
// }

// constexpr
// long double
// erf_cf(const long double x, const int depth)
// {
//     return ( depth == 55 ? x : x + (depth/2.0)/erf_cf(x,depth+1) );
// }

// constexpr
// long double
// erf_int(const long double x)
// {
//     return ( 1.0 - (exp(-x*x)/GCEM_SQRT_PI) / erf_cf(x,1) );
// }

#endif
