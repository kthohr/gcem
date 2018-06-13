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
 * compile-time exponential function
 */

#ifndef _gcem_exp_HPP
#define _gcem_exp_HPP

namespace internal
{

template<typename T>
constexpr
T
exp_cf_recur(const T x, const int depth)
{
    return( depth < GCEM_EXP_MAX_ITER_SMALL ? \
            // if
                depth == 1 ? \
                    T(1) - x/exp_cf_recur(x,depth+1) : 
                    T(1) + x/T(depth - 1) - x/depth/exp_cf_recur(x,depth+1) : 
             // else
                T(1) );
}

template<typename T>
constexpr
T
exp_cf(const T x)
{
    return( T(1)/exp_cf_recur(x,1) );
}

template<typename T>
constexpr
T
exp_split(const T x)
{
    return( pow_integral(GCEM_E,find_whole(x)) * exp_cf(find_fraction(x)) );
}

template<typename T>
constexpr
T
exp_check(const T x)
{
    return( GCLIM<T>::epsilon() > abs(x) ? \
            // if
                T(1) : 
            // else
                abs(x) < T(2) ? exp_cf(x) : \
                                exp_split(x) );
}

}

//
// main function

template<typename T>
constexpr
return_t<T>
exp(const T x)
{
    return internal::exp_check<return_t<T>>(x);
}

// #ifndef GCEM_EXP_TOL
//     #define GCEM_EXP_TOL 1E-14
// #endif

// taylor approximation
// constexpr
// double
// exp_taylor(const double x, const int order)
// {
//     return( order == 1 ? 1.0 + x : ( pow(x,order) / factorial(order) ) + exp_taylor(x,order-1) );
// }

// constexpr
// double
// exp_int(const double x)
// {
//     return( pow(GCEM_E,find_whole(x)) * exp_taylor(find_fraction(x),13) );
// }

// second form of the continued fraction
// constexpr
// long double
// exp_cf(const long double x, const int depth)
// {
//     return( depth == 205 ? (long double)(depth - 1 + x) : depth == 1 ? 1 - x/exp_cf(x,depth+1) : (depth - 1) + x - (depth - 1)*x/exp_cf(x,depth+1) );
// }

// constexpr
// long double
// exp_cf(const long double x, const int depth)
// {
//     return( abs((depth - 1)*x/depth) < GCEM_EXP_TOL ? (long double)(depth + x) : depth == 1 ? 1 - x/exp_cf(x,depth+1) : (depth - 1) + x - (depth - 1)*x/exp_cf(x,depth+1) );
// }

#endif
