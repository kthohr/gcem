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
 * compile-time square-root function
 */

#ifndef _gcem_sqrt_HPP
#define _gcem_sqrt_HPP

template<typename T>
constexpr
T
sqrt_recur(const T x, const T xn)
{
    return ( abs(xn - x/xn) < GCEM_SQRT_TOL ? xn : sqrt_recur(x,0.5*(xn+x/xn)) );
}

template<typename T>
constexpr
T
sqrt(const T x)
{
    return ( x < T(0.0) ? GCLIM<T>::quiet_NaN() :
             GCLIM<T>::epsilon() > abs(x) ? T(0.0) :
             x == T(1.0) ? x :
             //
             sqrt_recur(x,x/T(2.0)) );
}

#endif
