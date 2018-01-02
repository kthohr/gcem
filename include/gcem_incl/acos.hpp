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
 * compile-time arccosine function
 */

#ifndef _gcem_acos_HPP
#define _gcem_acos_HPP

template<typename T>
constexpr
T
acos_int(const T x)
{
    return ( abs(x) > T(1.0)                           ? GCEM_LIM<T>::quiet_NaN() :       // only defined on [-1,1]
             GCEM_LIM<T>::epsilon() > abs(x -  T(1.0)) ? T(0.0) :                         // indistinguishable from 1
             GCEM_LIM<T>::epsilon() > abs(x)           ? T(GCEM_HALF_PI) :                // indistinguishable from 0
                                                         atan( sqrt(T(1.0) - x*x)/x ) );
}

template<typename T>
constexpr
T
acos(const T x)
{
    return ( x > T(0.0) ? acos_int(x) : T(GCEM_PI) - acos_int(-x));
}

#endif
