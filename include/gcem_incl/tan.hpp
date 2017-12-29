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
 */

#ifndef _gcem_tan_HPP
#define _gcem_tan_HPP

template<typename T>
constexpr
T
tan_cf_recur(const T xx, const int depth, const int max_depth)
{
    return ( depth < max_depth ? T(2*depth - 1) - xx/tan_cf_recur(xx,depth+1,max_depth) : T(2*depth - 1) );
}

template<typename T>
constexpr
T
tan_cf_main(const T x)
{
    return ( x > 1.0 ? x/tan_cf_recur(x*x,1,35) : x/tan_cf_recur(x*x,1,25) );
}

template<typename T>
constexpr
T
tan_int(const T x)
{ // tan(x) = tan(x + pi)
    return ( x > T(GCEM_PI) ? tan_int(x - T(GCEM_PI)*( (int)(x/GCEM_PI) )) : tan_cf_main(x) );
}

template<typename T>
constexpr
T
tan(const T x)
{
    return ( GCEM_LIM<T>::epsilon() > abs(x) ? T(0.0) : ( x < T(0.0) ? -tan_int(-x) : tan_int(x) ) );
}

#endif
