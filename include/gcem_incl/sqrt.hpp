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
 * compile-time square-root function
 */

#ifndef _gcem_sqrt_HPP
#define _gcem_sqrt_HPP

template<typename T>
constexpr
T
sqrt_recur(const T x, const T xn)
{
    return ( abs(xn - x/xn) < GCEM_SQRT_TOL ? \
             // if
                xn :
             // else
                sqrt_recur(x,T(0.5)*(xn + x/xn)) );
}

template<typename T>
constexpr
T
sqrt_check(const T x)
{
    return ( x < T(0.0) ? GCLIM<T>::quiet_NaN() :
             //
             GCLIM<T>::epsilon() > abs(x)        ? T(0.0) :
             GCLIM<T>::epsilon() > abs(T(1.0)-x) ? x :
             //
             sqrt_recur(x,x/T(2.0)) );
}

template<typename T>
constexpr
return_t<T>
sqrt(const T x)
{
    return sqrt_check(return_t<T>(x));
}

#endif
