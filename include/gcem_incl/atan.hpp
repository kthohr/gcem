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
 * compile-time arctangent function
 */

// see
// http://functions.wolfram.com/ElementaryFunctions/ArcTan/10/0001/

#ifndef _gcem_atan_HPP
#define _gcem_atan_HPP

constexpr
long double
atan_cf(const long double xx, const int depth)
{
    return ( depth == GCEM_ATAN_MAX_ITER ? (long double)(2*depth - 1) : (2*depth - 1) + depth*depth*xx/atan_cf(xx,depth+1) );
}

constexpr
long double
atan_int(const long double x)
{
    return ( x/atan_cf(x*x,1) );
}

constexpr
long double
atan(const long double x)
{
    return ( x == 0 ? 0 : ( x > 0 ? atan_int(x) : -atan_int(-x) ) );
}

#endif
