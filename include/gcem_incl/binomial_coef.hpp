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

template<typename rT>
constexpr
rT
binomial_coef_recur(const uint_t n, const uint_t k)
{
    return( k > 0U ?
            // if
            // Division works with int types because of i sequential numbers,
            // one is divisible by i. Thus, their product is also divisible by i
                binomial_coef_recur<rT>(n,k-1) * static_cast<rT>(n - k + 1) / k :
            // else
                rT(1) );
}

}

// main function: 'n choose k'
template<typename rT = uint_t>
constexpr
rT
binomial_coef(const uint_t n, const uint_t k)
{
  return  // if - edge cases
          (n == 0U && k != 0U) ? rT(0) :  // deals with 0 choose 0 case
          // else
          k > n - k ? internal::binomial_coef_recur<rT>(n,n-k) :
                      internal::binomial_coef_recur<rT>(n,k);
}

#endif
