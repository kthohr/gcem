/*################################################################################
  ##
  ##   Copyright (C) 2016-2017 Keith O'Hara
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

constexpr
long double
tanh_cf(const long double xx, const int depth)
{
    return ( depth == GCEM_TANH_MAX_ITER ? 2*depth - 1 : (2*depth - 1) + xx/tanh_cf(xx,depth+1) );
}

constexpr
long double
tanh_int(const long double x)
{
    return ( x/tanh_cf(x*x,1) );
}

constexpr
long double
tanh(const long double x)
{
    return ( x == 0 ? 0 : ( x > 0 ? tanh_int(x) : -tanh_int(-x) ) );
}

#endif
