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
 * compile-time hyperbolic cosine function
 */

#ifndef _gcem_cosh_HPP
#define _gcem_cosh_HPP

template<typename T>
constexpr
T
cosh(const T x)
{
    return ( GCEM_LIM<T>::epsilon() > abs(x) ? T(1.0) : (exp(x) + exp(-x)) / T(2.0) );
}

#endif
