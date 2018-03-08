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
 * compile-time inverse hyperbolic tangent function
 */

#ifndef _gcem_atanh_HPP
#define _gcem_atanh_HPP

template<typename T>
constexpr
T
atanh_int(const T x)
{
    return ( // function is defined for |x| < 1
             T(1.0) < abs(x)              ? GCLIM<T>::quiet_NaN() :
             // indistinguishable from zero
             GCLIM<T>::epsilon() > abs(x) ? T(0.0) :
             // else
             log( (T(1.0) + x)/(T(1.0) - x) ) / T(2.0) );
}

template<typename T>
constexpr
return_t<T>
atanh(const T x)
{
    return atanh_int(return_t<T>(x));
}

#endif
