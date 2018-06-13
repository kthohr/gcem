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
 * compile-time factorial function
 */

#ifndef _gcem_factorial_HPP
#define _gcem_factorial_HPP

namespace internal
{

// T should be int, long int, unsigned int, etc.

template<typename T>
constexpr
T
factorial_table(const T x)
{   // table for x! when x = {2,...,10}
    return( x == 2 ? 2     : x == 3 ? 6      :
            x == 4 ? 24    : x == 5 ? 120    :
            x == 6 ? 720   : x == 7 ? 5040   :
            x == 8 ? 40320 : x == 9 ? 362880 : 3628800);
}

template<typename T>
constexpr
T
factorial_integer(const T x)
{
    return( x == 0 ? 1 :
            x == 1 ? x :
            //
            x < 11 ? factorial_table(x) :
                     x*factorial_integer(x-1) );
}

}

//
// main function

template<typename T>
constexpr
T
factorial(const T x)
{
    return( std::is_integral<T>::value ? \
            // if
                internal::factorial_integer(x) :
            // else
                tgamma(x + 1) );
}

#endif
