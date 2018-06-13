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
 * compile-time hyperbolic tangent function
 */

#ifndef _gcem_tanh_HPP
#define _gcem_tanh_HPP

namespace internal
{

template<typename T>
constexpr
T
tanh_cf(const T xx, const int depth)
{
    return( depth < GCEM_TANH_MAX_ITER ? \
            // if
                (2*depth - 1) + xx/tanh_cf(xx,depth+1) :
            // else
                T(2*depth - 1) );
}

template<typename T>
constexpr
T
tanh_begin(const T x)
{
    return( x/tanh_cf(x*x,1) );
}

template<typename T>
constexpr
T
tanh_check(const T x)
{
    return( // indistinguishable from zero
             GCLIM<T>::epsilon() > abs(x) ? \
                T(0) :
             // else
                x < T(0) ? \
                    - tanh_begin(-x) : 
                      tanh_begin( x) );
}

}

//
// main function

template<typename T>
constexpr
return_t<T>
tanh(const T x)
{
    return internal::tanh_check<return_t<T>>(x);
}

#endif
