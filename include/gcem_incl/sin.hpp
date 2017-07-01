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
 * compile-time sine function using tan(x/2)
 * see eq. 5.4.8 in Numerical Recipes
 *
 * Keith O'Hara
 * 06/25/2017
 *
 * This version:
 * 07/01/2017
 */

#ifndef _gcem_sin_HPP
#define _gcem_sin_HPP

constexpr
long double
sin_int(const long double x)
{
    return 2*x/(1+x*x);
}

constexpr
long double
sin(const long double x)
{
    return ( x == 0 ? 0 : sin_int(tan(x/2)) );
}

#endif
