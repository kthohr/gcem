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
 * compile-time natural logarithm function
 */

#ifndef _gcem_log_HPP
#define _gcem_log_HPP

// continued fraction seems to be a better approximation for small x
// see
// http://functions.wolfram.com/ElementaryFunctions/Log/10/0005/

template<typename T>
constexpr
T
log_int_cf_main(const T xx, const int depth)
{
    // return ( abs(depth*depth*xx/(2*(depth+1) - 1) ) < GCEM_LOG_TOL ? (T)(2*depth - 1) : (2*depth - 1) - depth*depth*xx/log_int_cf_main(xx,depth+1) );
    return ( depth < GCEM_LOG_MAX_ITER_SMALL ? T(2*depth - 1) - depth*depth*xx/log_int_cf_main(xx,depth+1) : T(2*depth - 1) );
}

template<typename T>
constexpr
T
log_int_cf_begin(const T x)
{ 
    return ( 2*x/log_int_cf_main(x*x,1) );
}

template<typename T>
constexpr
T
log_int_main(const T x)
{ 
    return ( log_int_cf_begin((x - T(1.0))/(x + T(1.0))) );
}

constexpr
long double
log_int_mantissa_integer(const int x)
{
    return ( x == 2 ? 0.69314718055994530942L : x == 3 ? 1.09861228866810969140L : x == 4  ? 1.38629436111989061883L : 
             x == 5 ? 1.60943791243410037460L : x == 6 ? 1.79175946922805500081L : x == 7  ? 1.94591014905531330511L : 
             x == 8 ? 2.07944154167983592825L : x == 9 ? 2.19722457733621938279L : x == 10 ? 2.30258509299404568402L : 0.0L );
}

template<typename T>
constexpr
T
log_int_mantissa(const T x)
{   // divide by the integer part of x, which will be in [1,10], then adjust using tables
    return ( log_int_main(x/static_cast<int>(x)) + T(log_int_mantissa_integer(static_cast<int>(x))) );
}

template<typename T>
constexpr
T
log_int_breakup(const T x)
{   // x = a*b, where b = 10^c
    return ( log_int_mantissa(mantissa(x)) + T(2.30258509299404568402L)*(find_exponent(x,0)) );
}

template<typename T>
constexpr
T
log(const T x)
{
    return ( GCLIM<T>::epsilon() > x               ? - GCLIM<T>::infinity() :
             GCLIM<T>::epsilon() > abs(x - T(1.0)) ? T(0.0) : 
             //
             x < T(0.5) ? log_int_breakup(x) : 
             x > T(1.5) ? log_int_breakup(x) : log_int_main(x) );
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
// log_int_cf_begin(const long double xx, const int depth)
// {
//     return ( depth == 505 ? (long double)(2*depth - 1) : (2*depth - 1) - depth*depth*xx/log_int_cf_begin(xx,depth+1) );
// }

#endif
