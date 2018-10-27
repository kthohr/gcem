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

#ifndef _gcem_binomial_coef_HPP
#define _gcem_binomial_coef_HPP

namespace internal
{

template<typename pT, typename eT>
constexpr
eT
binomial_coef_recur(const pT n, const pT k)
{
    return( // edge cases
                (k == pT(0) || n == k) ? eT(1) : // deals with 0 choose 0 case
                n == pT(0) ? eT(0) :
            // else
                binomial_coef_recur<pT,eT>(n-1,k-1) + binomial_coef_recur<pT,eT>(n-1,k) );
}

}

/**
 * Compile-time binomial coefficient
 *
 * @param n integral-valued input.
 * @param k integral-valued input.
 * @return computes the Binomial coefficient
 * \f[ \binom{n}{k} = \frac{n!}{k!(n-k)!} \f]
 * also known as '\c n choose \c k '.
 */

template<typename pT, typename eT = pT>
constexpr
eT
binomial_coef(const pT n, const pT k)
{
    return( std::is_integral<pT>::value ? \
        // if
            internal::binomial_coef_recur<pT,eT>(n,k) :
        // else
            internal::binomial_coef_recur<ullint_t,ullint_t>(n,k) );
}

#endif