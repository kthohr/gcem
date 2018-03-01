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
 * compile-time binomial coefficient
 */

#ifndef _gcem_binomial_coef_HPP
#define _gcem_binomial_coef_HPP

constexpr
long double
binomial_coef_int(const int n, const int k, const int count)
{
    return ( count < k ? binomial_coef_int(n,k,count+1) * static_cast<long double>(n - k + count) / count : static_cast<long double>(n) / count );
}

constexpr
long double
binomial_coef(const int n, const int k)
{
    return ( k > n - k ? binomial_coef_int(n,n-k,1) : binomial_coef_int(n,k,1) );
}

#endif