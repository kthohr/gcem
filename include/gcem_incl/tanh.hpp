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
 * compile-time hyperbolic tangent function
 */

#ifndef _gcem_tanh_HPP
#define _gcem_tanh_HPP

template<typename T>
constexpr
T
tanh_cf(const T xx, const int depth)
{
    return ( depth < GCEM_TANH_MAX_ITER ? (2*depth - 1) + xx/tanh_cf(xx,depth+1) : T(2*depth - 1) );
}

template<typename T>
constexpr
T
tanh_int(const T x)
{
    return ( x/tanh_cf(x*x,1) );
}

template<typename T>
constexpr
T
tanh(const T x)
{
    return ( GCEM_LIM<T>::epsilon() > abs(x) ? T(0.0) : ( x < T(0.0) ? -tanh_int(-x) : tanh_int(x) ) );
}

#endif
