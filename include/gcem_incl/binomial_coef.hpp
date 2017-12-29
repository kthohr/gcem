
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
 * compile-time binomial coefficient
 */

#ifndef _gcem_binomial_coef_HPP
#define _gcem_binomial_coef_HPP

constexpr
long double
binomial_coef_int(const int n, const int k, const int count)
{
    return ( count < k ? binomial_coef_int(n,k,count+1) * static_cast<long double>(n - k + count) / count : static_cast<long double>(n) / count );
}

constexpr
long double
binomial_coef(const int n, const int k)
{
    return ( k > n - k ? binomial_coef_int(n,n-k,1) : binomial_coef_int(n,k,1) );
}

#endif