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

#ifndef _gcem_lcm_HPP
#define _gcem_lcm_HPP

/**
 * Compile-time least common multiple (LCM) function
 *
 * @param a integral-valued input.
 * @param b integral-valued input.
 * @return the least common multiple between integers \c a and \c b using the representation \f[ \text{lcm}(a,b) = \dfrac{| a b |}{\text{gcd}(a,b)} \f]
 * where \f$ \text{gcd}(a,b) \f$ denotes the greatest common divisor between \f$ a \f$ and \f$ b \f$.
 */

template<typename T>
constexpr
T
lcm(const T a, const T b)
{
    return abs(a * (b / gcd(a,b)));
}

#endif
