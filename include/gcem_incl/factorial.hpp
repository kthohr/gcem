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
 * compile-time factorial function
 *
 * Keith O'Hara
 * 06/23/2016
 *
 * This version:
 * 07/10/2017
 */

#ifndef _gcem_factorial_HPP
#define _gcem_factorial_HPP

constexpr
int
factorial(const int x) {
    return ( x == 0 ? 1 : x == 1 ? x : x*factorial(x-1));
}

#endif
