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
 * compile-time incomplete beta function
 *
 * see eq. 18.5.17a in the Handbook of Continued Fractions for Special Functions
 */

#ifndef _gcem_incomplete_beta_HPP
#define _gcem_incomplete_beta_HPP

namespace internal
{

template<typename T>
constexpr T incomplete_beta_cf(const T a, const T b, const T z, const T c_j, const T d_j, const T f_j, const int depth);

//
// coefficients; see eq. 18.5.17b

template<typename T>
constexpr
T
incomplete_beta_coef_even(const T a, const T b, const T z, const int k)
{
    return( -z*(a + k)*(a + b + k)/( (a + 2*k)*(a + 2*k + T(1)) ) );
}

template<typename T>
constexpr
T
incomplete_beta_coef_odd(const T a, const T b, const T z, const int k)
{
    return( z*k*(b - k)/((a + 2*k - T(1))*(a + 2*k)) );
}

template<typename T>
constexpr
T
incomplete_beta_coef(const T a, const T b, const T z, const int depth)
{
    return( !is_odd(depth) ? incomplete_beta_coef_even(a,b,z,depth/2) :
                              incomplete_beta_coef_odd(a,b,z,(depth+1)/2) );
}

//
// update formulae for the modified Lentz method

template<typename T>
constexpr
T
incomplete_beta_c_update(const T a, const T b, const T z, const T c_j, const int depth)
{
    return( T(1) + incomplete_beta_coef(a,b,z,depth)/c_j );
}

template<typename T>
constexpr
T
incomplete_beta_d_update(const T a, const T b, const T z, const T d_j, const int depth)
{
    return( T(1) / (T(1) + incomplete_beta_coef(a,b,z,depth)*d_j) );
}

//
// convergence-type condition

template<typename T>
constexpr
T
incomplete_beta_decision(const T a, const T b, const T z, const T c_j, const T d_j, const T f_j, const int depth)
{
    return( // tolerance check
                abs(c_j*d_j - T(1)) < GCEM_INCML_BETA_TOL ? f_j*c_j*d_j :
            // max_iter check
                depth < GCEM_INCML_BETA_MAX_ITER ? \
                    // if
                        incomplete_beta_cf(a,b,z,c_j,d_j,f_j*c_j*d_j,depth+1) :
                    // else 
                        f_j*c_j*d_j );
}

template<typename T>
constexpr
T
incomplete_beta_cf(const T a, const T b, const T z, const T c_j, const T d_j, const T f_j, const int depth)
{
    return  incomplete_beta_decision(a,b,z,
                incomplete_beta_c_update(a,b,z,c_j,depth),
                incomplete_beta_d_update(a,b,z,d_j,depth),
                f_j,depth);
}

//
// x^a (1-x)^{b} / (a beta(a,b)) * cf

template<typename T>
constexpr
T
incomplete_beta_begin(const T a, const T b, const T z)
{
    return  ( (exp(a*log(z) + b*log(T(1)-z) - lbeta(a,b)) / a) * \
                incomplete_beta_cf(a,b,z,T(1), 
                    incomplete_beta_d_update(a,b,z,T(1),0),
                    incomplete_beta_d_update(a,b,z,T(1),0),1)
            );
}

template<typename T>
constexpr
T
incomplete_beta_check(const T a, const T b, const T z)
{
    return( // indistinguishable from zero
            GCLIM<T>::epsilon() > z ? \
                T(0) :
            // parameter check for performance
            (a + T(1))/(a + b + T(2)) > z ? \
                incomplete_beta_begin(a,b,z) :
                T(1) - incomplete_beta_begin(b,a,T(1) - z) );
}

}

//
// main function

template<typename eT, typename pT>
constexpr
eT
incomplete_beta(const pT a, const pT b, const eT z)
{
    return internal::incomplete_beta_check<eT>(a,b,z);
}

#endif
