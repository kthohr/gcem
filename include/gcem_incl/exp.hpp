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
 * compile-time exponential function
 */

#ifndef _gcem_exp_HPP
#define _gcem_exp_HPP

template<typename T>
constexpr
T
exp_cf_int(const T x, const int depth)
{
    return ( depth < GCEM_EXP_MAX_ITER_SMALL ? ( depth == 1 ? T(1.0) - x/exp_cf_int(x,depth+1) : T(1.0) + x/T(depth - 1) - x/depth/exp_cf_int(x,depth+1) ) : T(1.0) );
}

template<typename T>
constexpr
T
exp_cf(const T x)
{
    return ( T(1.0)/exp_cf_int(x,1) );
}

template<typename T>
constexpr
T
exp_split(const T x)
{
    return ( pow(GCEM_E,find_whole(x)) * exp_cf(find_fraction(x)) );
}

template<typename T>
constexpr
T
exp(const T x)
{
    return ( x == T(0.0) ? T(1.0) : ( abs(x) < T(2.0) ? exp_cf(x) : exp_split(x) ) );
}

// #ifndef GCEM_EXP_TOL
//     #define GCEM_EXP_TOL 1E-14
// #endif

// taylor approximation
// constexpr
// double
// exp_taylor(const double x, const int order)
// {
//     return ( order == 1 ? 1.0 + x : ( pow(x,order) / factorial(order) ) + exp_taylor(x,order-1) );
// }

// constexpr
// double
// exp_int(const double x)
// {
//     return ( pow(GCEM_E,find_whole(x)) * exp_taylor(find_fraction(x),13) );
// }

// second form of the continued fraction
// constexpr
// long double
// exp_cf(const long double x, const int depth)
// {
//     return ( depth == 205 ? (long double)(depth - 1 + x) : depth == 1 ? 1 - x/exp_cf(x,depth+1) : (depth - 1) + x - (depth - 1)*x/exp_cf(x,depth+1) );
// }

// constexpr
// long double
// exp_cf(const long double x, const int depth)
// {
//     return ( abs((depth - 1)*x/depth) < GCEM_EXP_TOL ? (long double)(depth + x) : depth == 1 ? 1 - x/exp_cf(x,depth+1) : (depth - 1) + x - (depth - 1)*x/exp_cf(x,depth+1) );
// }

#endif
