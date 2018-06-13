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

namespace internal
{

// 50 point Gauss-Legendre quadrature

template<typename T>
constexpr
T
incomplete_gamma_quad_inp_vals(const T lb, const T ub, const int counter)
{
    return (ub-lb) * gauss_legendre_50_points[counter] / T(2) + (ub + lb) / T(2);
}

template<typename T>
constexpr
T
incomplete_gamma_quad_weight_vals(const T lb, const T ub, const int counter)
{
    return (ub-lb) * gauss_legendre_50_weights[counter] / T(2);
}

template<typename T>
constexpr
T
incomplete_gamma_quad_fn(const T x, const T a, const T lg_term)
{
    return exp( -x + (a-T(1))*log(x) - lg_term );
}

template<typename T>
constexpr
T
incomplete_gamma_quad_recur(const T lb, const T ub, const T a, const T lg_term, const int counter)
{
    return( counter < 49 ? \
            // if 
                incomplete_gamma_quad_fn(incomplete_gamma_quad_inp_vals(lb,ub,counter),a,lg_term) \
                    * incomplete_gamma_quad_weight_vals(lb,ub,counter) \
                    + incomplete_gamma_quad_recur(lb,ub,a,lg_term,counter+1) :
            // else
                incomplete_gamma_quad_fn(incomplete_gamma_quad_inp_vals(lb,ub,counter),a,lg_term) \
                    * incomplete_gamma_quad_weight_vals(lb,ub,counter) );
}

template<typename T>
constexpr
T
incomplete_gamma_quad_lb(const T a, const T z)
{
    return( a > T(1000) ? max(T(0),min(z,a) - 11*sqrt(a)) : // break integration into ranges
            a > T(800)  ? max(T(0),min(z,a) - 11*sqrt(a)) :
            a > T(500)  ? max(T(0),min(z,a) - 10*sqrt(a)) :
            a > T(300)  ? max(T(0),min(z,a) - 10*sqrt(a)) : 
            a > T(100)  ? max(T(0),min(z,a) -  9*sqrt(a)) :
            a > T(90)   ? max(T(0),min(z,a) -  9*sqrt(a)) :
            a > T(70)   ? max(T(0),min(z,a) -  8*sqrt(a)) :
            a > T(50)   ? max(T(0),min(z,a) -  7*sqrt(a)) :
            a > T(40)   ? max(T(0),min(z,a) -  6*sqrt(a)) :
            a > T(30)   ? max(T(0),min(z,a) -  5*sqrt(a)) :
            // else
                max(T(0),min(z,a)-4*sqrt(a)) );
}

template<typename T>
constexpr
T
incomplete_gamma_quad_ub(const T a, const T z)
{
    return( a > T(1000) ? min(z, a + 10*sqrt(a)) :
            a > T(800)  ? min(z, a + 10*sqrt(a)) :
            a > T(500)  ? min(z, a + 9*sqrt(a))  :
            a > T(300)  ? min(z, a + 9*sqrt(a))  : 
            a > T(100)  ? min(z, a + 8*sqrt(a))  :
            a > T(90)   ? min(z, a + 8*sqrt(a))  :
            a > T(70)   ? min(z, a + 7*sqrt(a))  :
            a > T(50)   ? min(z, a + 6*sqrt(a))  :
            a > T(40)   ? min(z, a + 5*sqrt(a))  :
            // else
                min(z, a + 4*sqrt(a)) );
}

template<typename T>
constexpr
T
incomplete_gamma_quad(const T a, const T z)
{
    return incomplete_gamma_quad_recur(incomplete_gamma_quad_lb(a,z), incomplete_gamma_quad_ub(a,z), a,lgamma(a),0);
}

// cf expansion
// see: http://functions.wolfram.com/GammaBetaErf/Gamma2/10/0009/

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
incomplete_gamma_cf_recur(const T a, const T z, const int depth)
{
    return( depth < GCEM_INCML_GAMMA_MAX_ITER ? \
            // if
                (a + depth - 1) + incomplete_gamma_cf_coef(a,z,depth)/incomplete_gamma_cf_recur(a,z,depth+1) :
            // else
                (a + depth - 1) );
}

template<typename T>
constexpr
T
incomplete_gamma_cf(const T a, const T z)
{   // lower (regularized) incomplete gamma function
    return( exp(a*log(z) - z) / tgamma(a) / incomplete_gamma_cf_recur(a,z,1) );
}

//

template<typename T>
constexpr
T
incomplete_gamma_check(const T a, const T z)
{
    return( GCLIM<T>::epsilon() > z ? \
                T(0) : 
            GCLIM<T>::epsilon() > a ? \
                T(1) : 
            // cf or quadrature
            a < T(10) ?
                incomplete_gamma_cf(a,z) :
            // else
                incomplete_gamma_quad(a,z) );
}

}

//
// main function

template<typename eT, typename pT>
constexpr
return_t<eT>
incomplete_gamma(const pT a, const eT z)
{
    return internal::incomplete_gamma_check<return_t<eT>>(a,z);
}

#endif
