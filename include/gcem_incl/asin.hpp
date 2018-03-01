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
 * compile-time arcsine function
 */

#ifndef _gcem_asin_HPP
#define _gcem_asin_HPP

template<typename T>
constexpr
T
asin_int(const T x)
{
    return ( x > T(1.0)                             ? GCLIM<T>::quiet_NaN() :    // only defined on [-1,1]
             GCLIM<T>::epsilon() > abs(x -  T(1.0)) ? T(GCEM_HALF_PI) :          // indistinguishable from 1
             GCLIM<T>::epsilon() > abs(x)           ? T(0.0) :                   // indistinguishable from 0
                                                      atan( x/sqrt(T(1.0) - x*x) ) );
}

template<typename T>
constexpr
T
asin(const T x)
{
    return ( x < T(0.0) ? - asin_int(-x) : asin_int(x) );
}

#endif
