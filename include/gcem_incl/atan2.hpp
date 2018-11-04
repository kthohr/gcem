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
   * compile-time 2-argument arctangent function
   */

   // see
   // http://functions.wolfram.com/ElementaryFunctions/ArcTan2/

#ifndef _gcem_atan2_HPP
#define _gcem_atan2_HPP

#include "atan.hpp"

/**
 * Compile-time 2-argument arctangent function
 *
 * @param y a real-valued input.
 * @param x a real-valued input.
 * @return the angle in radians of the vector <x, y>, in the range \f[ \left[ -\pi, \pi \right] \f].
 *
 * @note Behavior is undefined if both @p y and @p x are 0.
 */

template<typename T>
constexpr
return_t<T>
atan2(const T y, const T x)
noexcept {
    return( // Positive x half plane: just use atan().
            x > T(0) ? atan(y / x) :
            // Negative x half plane: need to adjust atan() result.
            x < T(0) ? atan(y / x) + (y >= T(0) ? GCEM_PI : -GCEM_PI) :
            // On the y-axis: answer is pi or -pi.
            y > T(0) ? GCEM_HALF_PI : -GCEM_HALF_PI);
}

#endif
