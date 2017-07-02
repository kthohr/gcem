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
 * compile-time natural logarithm function
 *
 * Keith O'Hara
 * 06/25/2017
 *
 * This version:
 * 07/02/2017
 */

#ifndef _gcem_log_HPP
#define _gcem_log_HPP

#ifndef GCEM_LOG_TOL
    #define GCEM_LOG_TOL 1E-14
#endif

template<typename T>
constexpr
T
log_taylor_int(const T xx, int order)
{
    return ( order == 505 ? 1.0 : (T)(1.0 / (2.0*order-1.0)) + xx*log_taylor_int(xx,order+1) );
}

template<typename T>
constexpr
T
log_taylor(const T x)
{ 
    return ( 2*x*log_taylor_int(x*x,1) );
}

// continued fraction seems to be a better approximation for small x
template<typename T>
constexpr
T
log_cf_int(const T xx, const int depth)
{
    // return ( abs(depth*depth*xx/(2*(depth+1) - 1) ) < GCEM_LOG_TOL ? (T)(2*depth - 1) : (2*depth - 1) - depth*depth*xx/log_cf_int(xx,depth+1) );
    return ( depth == 505 ? (T)(2*depth - 1) : (2*depth - 1) - depth*depth*xx/log_cf_int(xx,depth+1) );
}

template<typename T>
constexpr
T
log_cf(const T x)
{ 
    return ( 2*x/log_cf_int(x*x,1) );
}

template<typename T>
constexpr
T
log_int(const T x)
{ 
    return ( log_cf((x-1.0)/(x+1.0)) );
    // return ( log_taylor((x-1.0)/(x+1.0)) );
}

template<typename T>
constexpr
T
log(const T x)
{
    // return ( x == 1 ? 0 : log_int(mantissa(x)) + 2.3025850929940459011*(find_exponent(x,0)) );
    return ( x == 1 ? 0 : log_int(x) );
}

// using Newton-Raphson
// constexpr
// double
// log_recur(const double y, const double x)
// {
//     return ( abs(x/exp(y) - 1) < GCEM_LOG_TOL ? y : log_recur(y-1+x/exp(y),x) );
// }

// constexpr
// long double
// log_cf(const long double xx, const int depth)
// {
//     return ( depth == 505 ? (long double)(2*depth - 1) : (2*depth - 1) - depth*depth*xx/log_cf(xx,depth+1) );
// }

#endif
