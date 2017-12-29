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
 * compile-time inverse hyperbolic tangent function
 */

#ifndef _gcem_atanh_HPP
#define _gcem_atanh_HPP

template<typename T>
constexpr
T
atanh(const T x)
{
    return ( T(1.0) < abs(x)                 ? GCEM_LIM<T>::quiet_NaN() : // function is defined for |x| < 1
             GCEM_LIM<T>::epsilon() > abs(x) ? T(0.0) : 
                                               log( (T(1.0L) + x)/(T(1.0) - x) ) / T(2.0) );
}

#endif
