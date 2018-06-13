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

namespace internal
{

template<typename T>
constexpr
T
asin_compute(const T x)
{
    return( // only defined on [-1,1]
            x > T(1) ? \
                GCLIM<T>::quiet_NaN() :
            // indistinguishable from one or zero
            GCLIM<T>::epsilon() > abs(x -  T(1)) ? \
                T(GCEM_HALF_PI) :
            GCLIM<T>::epsilon() > abs(x) ? \
                T(0) :
            // else
                atan( x/sqrt(T(1) - x*x) ) );
}

template<typename T>
constexpr
T
asin_check(const T x)
{
    return( x < T(0) ? - asin_compute(-x) : asin_compute(x) );
}

}

//
// main function

template<typename T>
constexpr
return_t<T>
asin(const T x)
{
    return internal::asin_check<return_t<T>>(x);
}

#endif
