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
 * compile-time power function
 */

#ifndef _gcem_pow_integral_HPP
#define _gcem_pow_integral_HPP

namespace internal
{

// integral-valued powers
// using method described in https://en.wikipedia.org/wiki/Exponentiation_by_squaring

template<typename Ta, typename Tb>
constexpr
Ta
pow_integral_compute_recur(const Ta base, const Ta val, const Tb exp_term)
{
    return( exp_term > Tb(1) ? \
                (is_odd(exp_term) ? \
                    pow_integral_compute_recur(base*base,val*base,exp_term/2) :
                    pow_integral_compute_recur(base*base,val,exp_term/2)) :
                (exp_term == Tb(1) ? val*base : val) );
}

template<typename Ta, typename Tb>
constexpr
Ta
pow_integral_compute(const Ta base, const Tb exp_term)
{
    return( exp_term == Tb(3) ? \
                base*base*base :
            exp_term == Tb(2) ? \
                base*base :
            exp_term == Tb(1) ? \
                base :
            exp_term == Tb(0) ? \
                Ta(1) :
            // check for overflow
            exp_term == GCLIM<Tb>::min() ? \
                Ta(0) :
            exp_term == GCLIM<Tb>::max() ? \
                GCLIM<Ta>::infinity() :
            // else
                exp_term < Tb(0) ? \
                //
                    Ta(1) / pow_integral_compute(base, - exp_term) : 
                //
                    pow_integral_compute_recur(base,Ta(1),exp_term) );
}

}

//
// main function

template<typename Ta, typename Tb>
constexpr
return_t<Ta>
pow_integral(const Ta base, const Tb exp_term)
{
    return internal::pow_integral_compute(return_t<Ta>(base),exp_term);
}

#endif
