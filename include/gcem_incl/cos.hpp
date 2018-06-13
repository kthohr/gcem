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
 * compile-time cosine function using tan(x/2)
 */

#ifndef _gcem_cos_HPP
#define _gcem_cos_HPP

namespace internal
{

template<typename T>
constexpr
T
cos_compute(const T x)
{
    return( T(1) - x*x)/(T(1) + x*x );
}

template<typename T>
constexpr
T
cos_check(const T x)
{
    return( // indistinguishable from 0
            GCLIM<T>::epsilon() > abs(x) ? 
                T(1) :
            // else
                cos_compute( tan(x/T(2)) ) );
}

}

//
// main function

template<typename T>
constexpr
return_t<T>
cos(const T x)
{
    return internal::cos_check<return_t<T>>(x);
}

#endif
