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
 * compile-time tangent function
 */

#ifndef _gcem_tan_HPP
#define _gcem_tan_HPP

namespace internal
{

template<typename T>
constexpr
T
tan_cf_recur(const T xx, const int depth, const int max_depth)
{
    return( depth < max_depth ? \
            // if
                T(2*depth - 1) - xx/tan_cf_recur(xx,depth+1,max_depth) :
            // else
                T(2*depth - 1) );
}

template<typename T>
constexpr
T
tan_cf_main(const T x)
{
    return( x > T(1) ? \
            // if
                x/tan_cf_recur(x*x,1,35) :
            // else
                x/tan_cf_recur(x*x,1,25) );
}

template<typename T>
constexpr
T
tan_begin(const T x, const int count = 0)
{   // tan(x) = tan(x + pi)
    return( x > T(GCEM_PI) ? \
            // if
                count > 1 ? GCLIM<T>::quiet_NaN() : // protect against undefined behavior
                tan_begin( x - T(GCEM_PI) * internal::floor(x/T(GCEM_PI)), count+1 ) :
            // else 
                tan_cf_main(x) );
}

template<typename T>
constexpr
T
tan_check(const T x)
{
    return( // indistinguishable from zero 
            GCLIM<T>::epsilon() > abs(x) ? \
                T(0) :
            // else
                x < T(0) ? \
                    - tan_begin(-x) : 
                      tan_begin( x) );
}

}

//
// main function

template<typename T>
constexpr
return_t<T>
tan(const T x)
{
    return internal::tan_check<return_t<T>>(x);
}

#endif
