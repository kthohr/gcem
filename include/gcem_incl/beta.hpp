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

#ifndef _gcem_beta_HPP
#define _gcem_beta_HPP

/**
 * Compile-time beta function
 *
 * @param a a real-valued input.
 * @param b a real-valued input.
 * @return the beta function using \f[ \text{B}(\alpha,\beta) := \int_0^1 t^{\alpha - 1} (1-t)^{\beta - 1} dt = \frac{\Gamma(\alpha)\Gamma(\beta)}{\Gamma(\alpha + \beta)} \f]
 * where \f$ \Gamma \f$ denotes the gamma function.
 */

template<typename T>
constexpr
return_t<T>
beta(const T a, const T b)
{
    return exp( lbeta<return_t<T>>(a,b) );
}

#endif
