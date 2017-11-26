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
 * compile-time mantissa function
 */

#ifndef _gcem_mantissa_HPP
#define _gcem_mantissa_HPP

template<typename T>
constexpr
T
mantissa(const T x)
{
    return ( x < T(1.0) ? mantissa(x*10) : ( x > T(10.0) ? mantissa(x*0.1) : x ) );
}

#endif
