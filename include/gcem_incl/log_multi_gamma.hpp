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
 * log multivariate gamma function
 */

#ifndef _gcem_log_multi_gamma_HPP
#define _gcem_log_multi_gamma_HPP

// see https://en.wikipedia.org/wiki/Multivariate_gamma_function

template<typename T>
constexpr
T
log_multi_gamma(const T a, const int p)
{
    return ( p == 1 ? lgamma(a) : 
             p < 1  ? GCLIM<T>::quiet_NaN() :
             //
             T(GCEM_LOG_PI) * (p - T(1.0))/T(2.0) + lgamma(a) + log_multi_gamma(a - T(0.5),p-1) );
}

#endif
