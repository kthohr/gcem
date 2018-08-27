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
 * Euclidean algorithm to find the GCD
 */

namespace internal
{

template<typename T>
constexpr
T
gcd_recur(T a, T b)
{
    return b == T(0) ? a : gcd_recur(b, a % b);
}

}

template<typename T>
constexpr
T
gcd(T a, T b)
{
    return( (a < T(0) || b < T(0)) ? \
            // sanity check
                gcd(abs(a),abs(b)) :
            //
            std::is_integral<T>::value ? \
                internal::gcd_recur(a,b) :
                internal::gcd_recur<ullint_t>(a,b) );
}
