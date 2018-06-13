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
 * compile-time sine function using tan(x/2)
 * 
 * see eq. 5.4.8 in Numerical Recipes
 */

#ifndef _gcem_sin_HPP
#define _gcem_sin_HPP

namespace internal
{

template<typename T>
constexpr
T
sin_compute(const T x)
{
    return T(2)*x/(T(1) + x*x);
}

template<typename T>
constexpr
T
sin_check(const T x)
{
    return( // indistinguishable from zero
            GCLIM<T>::epsilon() > abs(x) ? \
                T(0) :
            // else
                sin_compute( tan(x/T(2)) ) );
}

}

//
// main function

template<typename T>
constexpr
return_t<T>
sin(const T x)
{
    return internal::sin_check<return_t<T>>(x);
}

#endif
