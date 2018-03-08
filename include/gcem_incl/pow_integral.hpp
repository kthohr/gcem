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

// integral-valed powers

template<typename Ta, typename Tb>
constexpr
Ta
pow_integral_int(const Ta base, const Tb exp_term)
{
    return ( exp_term == Tb(1) ? base : 
             exp_term == Tb(0) ? Ta(1.0) : 
             //
             exp_term == GCLIM<Tb>::min() ? Ta(0.0) :
             exp_term == GCLIM<Tb>::max() ? GCLIM<Ta>::infinity() :
             //
             exp_term < Tb(0) ? Ta(1.0) / pow_integral_int(base, - exp_term) : 
                                base*pow_integral_int(base, exp_term - 1) );
}

template<typename Ta, typename Tb>
constexpr
return_t<Ta>
pow_integral(const Ta base, const Tb exp_term)
{
    return pow_integral_int(return_t<Ta>(base),exp_term);
}

#endif
