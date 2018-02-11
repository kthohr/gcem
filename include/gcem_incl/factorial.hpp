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
 * compile-time factorial function
 */

#ifndef _gcem_factorial_HPP
#define _gcem_factorial_HPP

// T should be int, long int, unsigned int, etc.

template<typename T>
constexpr
T
factorial_table(const T x)
{   // table for x! when x = {2,...,10}
    return ( x == 2 ? 2 :     x == 3 ? 6 :
             x == 4 ? 24 :    x == 5 ? 120 :
             x == 6 ? 720 :   x == 7 ? 5040 :
             x == 8 ? 40320 : x == 9 ? 362880 : 3628800);
}

template<typename T>
constexpr
T
factorial(const T x)
{
    return ( x == 0 ? 1 : x == 1 ? x :
             x < 11 ? factorial_table(x) : x*factorial(x-1) );
}

#endif
