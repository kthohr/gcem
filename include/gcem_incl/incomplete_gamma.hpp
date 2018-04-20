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
 * compile-time (regularized) incomplete gamma function
 */

#ifndef _gcem_incomplete_gamma_HPP
#define _gcem_incomplete_gamma_HPP

// for the expansion, see:
// http://functions.wolfram.com/GammaBetaErf/Gamma2/10/0009/

template<typename T>
constexpr
T
incomplete_gamma_cf_coef(const T a, const T z, const int depth)
{
    return( is_odd(depth) ? - (a - 1 + T(depth+1)/T(2)) * z : T(depth)/T(2) * z );
}

template<typename T>
constexpr
T
incomplete_gamma_cf_int(const T a, const T z, const int depth)
{
    return( depth < GCEM_INCML_GAMMA_MAX_ITER ? \
            // if
                (a + depth - 1) + incomplete_gamma_cf_coef(a,z,depth)/incomplete_gamma_cf_int(a,z,depth+1) :
            // else
                (a + depth - 1) );
}

template<typename T>
constexpr
T
incomplete_gamma_int(const T a, const T z)
{   // lower (regularized) incomplete gamma function
    return( exp(a*log(z) - z) / tgamma(a) / incomplete_gamma_cf_int(a,z,1) );
}

template<typename T>
constexpr
T
incomplete_gamma_check(const T a, const T z)
{
    return( // sanity checks
            GCLIM<T>::epsilon() > z ? \
                T(0) : 
            GCLIM<T>::epsilon() > a ? \
                T(1) : 
            // else
                incomplete_gamma_int(a,z) );
}

template<typename eT, typename pT>
constexpr
return_t<eT>
incomplete_gamma(const pT a, const eT z)
{
    return incomplete_gamma_check<return_t<eT>>(a,z);
}

#endif
