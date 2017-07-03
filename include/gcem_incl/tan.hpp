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
 * compile-time tangent function
 *
 * Keith O'Hara
 * 06/25/2017
 *
 * This version:
 * 07/01/2017
 */

#ifndef _gcem_tan_HPP
#define _gcem_tan_HPP

constexpr
long double
tan_cf(const long double xx, const int depth)
{
    return ( depth == GCEM_TAN_MAX_ITER ? 2*depth - 1 : (2*depth - 1) - xx/tan_cf(xx,depth+1) );
}

constexpr
long double
tan_int(const long double x)
{ // tan(x) = tan(x + pi)
    return ( x > GCEM_PI ? tan_int(x - (long double)GCEM_PI*( (int)(x/GCEM_PI) )) : x/tan_cf(x*x,1) );
}

constexpr
long double
tan(const long double x)
{
    return ( x == 0 ? 0 : ( x > 0 ? tan_int(x) : -tan_int(-x) ) );
}

#endif
