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

#ifndef _gcem_lmgamma_HPP
#define _gcem_lmgamma_HPP

namespace internal
{

// see https://en.wikipedia.org/wiki/Multivariate_gamma_function

template<typename Ta, typename Tb>
constexpr
Ta
lmgamma_recur(const Ta a, const Tb p)
{
    return( p == Tb(1) ? \
                lgamma(a) :
            p <  Tb(1) ? \
                GCLIM<Ta>::quiet_NaN() :
            // else
                Ta(GCEM_LOG_PI) * (p - Ta(1))/Ta(2) \
                    + lgamma(a) + lmgamma_recur(a - Ta(0.5),p-1) );
}

}

/**
 * Compile-time log multivariate gamma function
 *
 * @param a a real-valued input.
 * @param p integral-valued input.
 * @return computes log-multivariate gamma function via recursion
 * \f[ \Gamma_p(a) = \pi^{(p-1)/2} \Gamma(a) \Gamma_{p-1}(a-0.5) \f]
 * where \f$ \Gamma_1(a) = \Gamma(a) \f$.
 */

template<typename eT, typename pT>
constexpr
return_t<eT>
lmgamma(const pT a, const eT p)
{
    return internal::lmgamma_recur(return_t<eT>(a),p);
}

#endif
