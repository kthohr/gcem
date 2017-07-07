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

// continued fraction seems to be a better approximation for small x
template<typename T>
constexpr
T
log_cf_int(const T xx, const int depth)
{
    // return ( abs(depth*depth*xx/(2*(depth+1) - 1) ) < GCEM_LOG_TOL ? (T)(2*depth - 1) : (2*depth - 1) - depth*depth*xx/log_cf_int(xx,depth+1) );
    return ( depth == GCEM_LOG_MAX_ITER_SMALL ? (T)(2*depth - 1) : (2*depth - 1) - depth*depth*xx/log_cf_int(xx,depth+1) );
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
}

constexpr
long double
log_mantissa_integer(const int x)
{
    return ( x == 2 ? 0.69314718055994528623L : x == 3 ? 1.0986122886681097821L : x == 4  ? 1.3862943611198905725L : 
             x == 5 ? 1.6094379124341002818L  : x == 6 ? 1.7917594692280549573L : x == 7  ? 1.9459101490553132319L : 
             x == 8 ? 2.0794415416798357477L  : x == 9 ? 2.1972245773362195642L : x == 10 ? 2.3025850929940459011L : 0.0L );
}

template<typename T>
constexpr
T
log_mantissa(const T x)
{ // divide by the integer part of x, which will be in [1,10], the adjust using tables
    return ( log_int(x/(int)(x)) + log_mantissa_integer((int)(x)) );
}

template<typename T>
constexpr
T
log_breakup(const T x)
{ // x = a*b, where b = 10^c
    return ( log_mantissa(mantissa(x)) + 2.3025850929940459011*(find_exponent(x,0)) );
}

template<typename T>
constexpr
T
log(const T x)
{
    return ( x == 1 ? 0 : x < 0.5 ? log_breakup(x) : x > 1.5 ? log_breakup(x) : log_int(x) );
}

// using Taylor series

// template<typename T>
// constexpr
// T
// log_taylor_int(const T xx, int order)
// {
//     return ( order == GCEM_LOG_MAX_ITER_SMALL ? 1.0 : (T)(1.0 / (2.0*order-1.0)) + xx*log_taylor_int(xx,order+1) );
// }

// template<typename T>
// constexpr
// T
// log_taylor(const T x)
// { 
//     return ( 2*x*log_taylor_int(x*x,1) );
// }

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
