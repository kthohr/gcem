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

template<typename T>
constexpr
T
pow(const T base, const int exp_term)
{
    return ( exp_term == 1 ? base : exp_term == 0 ? T(1.0) : 
             exp_term == GCEM_LIM<int>::min() ? T(0.0) :
             exp_term == GCEM_LIM<int>::max() ? GCEM_LIM<T>::infinity() :
             exp_term < 0 ? T(1.0) / pow(base, -exp_term) : base*pow(base, exp_term-1) );
}

#endif
