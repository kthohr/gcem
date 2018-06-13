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
 * compile-time binomial coefficient: 'n choose k'
 */

#ifndef _gcem_binomial_coef_HPP
#define _gcem_binomial_coef_HPP

namespace internal
{

template<typename T>
constexpr
T
binomial_coef_recur(const uint_t n, const uint_t k, const uint_t count)
{
    return( count < k ? 
            // if
                binomial_coef_recur<T>(n,k,count+1) * static_cast<T>(n - k + count) / count : 
            // else
                static_cast<T>(n) / count );
}

template<typename T>
constexpr
T
binomial_coef_check(const uint_t n, const uint_t k)
{
    return( // edge cases
            k == 0U ? T(1) : // deals with 0 choose 0 case
            n == 0U ? T(0) :
            // else
            k > n - k ? binomial_coef_recur<T>(n,n-k,1U) :
                        binomial_coef_recur<T>(n,k,1U) );
}

}

//
// main function

template<typename pT, typename eT = double>
constexpr
eT
binomial_coef(const pT n, const pT k)
{
    return internal::binomial_coef_check<eT>(uint_t(n),uint_t(k));
}

#endif