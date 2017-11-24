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
 * find the fraction part of x = n + r, where -0.5 < r < 0.5
 */

#ifndef _gcem_find_fraction_HPP
#define _gcem_find_fraction_HPP

template<typename T>
constexpr
T
find_fraction(const T x)
{
    return ( abs(x - int(x)) > 0.5 ? x - int(x) - sgn(x) : x - int(x) );
}

#endif
