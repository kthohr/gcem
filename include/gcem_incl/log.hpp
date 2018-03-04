/*################################################################################
  ##
  ##   Copyright (C) 2016-2018 Keith O'Hara
  ##
  ##   This file is part of the GCE-Math C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
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
    return ( depth < GCEM_LOG_MAX_ITER_SMALL ? \
             // if 
                T(2*depth - 1) - depth*depth*xx/log_int_cf_main(xx,depth+1) :
             // else 
                T(2*depth - 1) );
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
    return ( x == 2  ? 0.69314718055994530942L : x == 3 ? 1.09861228866810969140L :
             x == 4  ? 1.38629436111989061883L : x == 5 ? 1.60943791243410037460L :
             x == 6  ? 1.79175946922805500081L : x == 7 ? 1.94591014905531330511L :
             x == 8  ? 2.07944154167983592825L : x == 9 ? 2.19722457733621938279L :
             x == 10 ? 2.30258509299404568402L : 0.0L );
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
    return ( log_int_mantissa(mantissa(x)) + T(GCEM_LOG_10)*(find_exponent(x,0)) );
}

template<typename T>
constexpr
T
log(const T x)
{
    return ( // x <= 0
             GCLIM<T>::epsilon() > x               ? - GCLIM<T>::infinity() :
             // indistinguishable from 1
             GCLIM<T>::epsilon() > abs(x - T(1.0)) ? T(0.0) : 
             // else
             (x < T(0.5) || x > T(1.5)) ? log_int_breakup(x) : 
                                          log_int_main(x) );
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
