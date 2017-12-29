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
 * compile-time arcsine function
 */

#ifndef _gcem_asin_HPP
#define _gcem_asin_HPP

template<typename T>
constexpr
T
asin_int(const T x)
{
    return ( x > T(1.0)                                ? GCEM_LIM<T>::quiet_NaN() : // only defined on [-1,1]
             GCEM_LIM<T>::epsilon() > abs(x -  T(1.0)) ? T(GCEM_HALF_PI) :          // indistinguishable from 1
             GCEM_LIM<T>::epsilon() > abs(x)           ? T(0.0) :                   // indistinguishable from 0
                                                         atan( x/sqrt(T(1.0) - x*x) ) );
}

template<typename T>
constexpr
T
asin(const T x)
{
    return ( x < T(0.0) ? - asin_int(-x) : asin_int(x) );
}

#endif
