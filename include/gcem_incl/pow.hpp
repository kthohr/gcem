/*################################################################################
  ##
  ##   Copyright (C) 2016-2018 Keith O'Hara
  ##
  ##   This file is part of the GCE-Math C++ library.
  ##
  ##   GCE-Math is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   GCE-Math is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

/*
 * compile-time power function
 */

#ifndef _gcem_pow_HPP
#define _gcem_pow_HPP

// integral-valed powers

template<typename Ta, typename Tb>
constexpr
Ta
pow_integral(const Ta base, const Tb exp_term)
{
    return ( exp_term == Tb(1) ? base : 
             exp_term == Tb(0) ? Ta(1.0) : 
             //
             exp_term == GCEM_LIM<Tb>::min() ? Ta(0.0) :
             exp_term == GCEM_LIM<Tb>::max() ? GCEM_LIM<Ta>::infinity() :
             //
             exp_term < Tb(0) ? Ta(1.0) / pow_integral(base, - exp_term) : 
                                base*pow_integral(base, exp_term - 1) );
}

// otherwise

template<typename T>
constexpr
T
pow_dbl(const T base, const T exp_term)
{
    return exp(exp_term*log(base));
}

//

template<typename Ta, typename Tb>
constexpr
Ta
pow(const Ta base, const Tb exp_term)
{
    return ( std::is_integral<Tb>::value ? \
             pow_integral(base,exp_term) : pow_dbl(base,Ta(exp_term)) );
}

#endif
