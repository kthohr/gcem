
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
 *
 * Keith O'Hara
 * 06/23/2016
 *
 * This version:
 * 07/01/2017
 */

#ifndef _gcem_binomial_coef_HPP
#define _gcem_binomial_coef_HPP

// inline
// double
// binomial_coef(int n, int k)
// {
//     const int k_run = (k > n - k) ? n - k : k;

//     double ret = 1.0;

//     for (int i=1; i <= k_run; i++) {
//         ret *= (double) (n - k_run + i) / i;
//     }

//     return ret;
// }

constexpr
long double
binomial_coef_int(const int n, const int k, const int count)
{
    return ( count < k ? binomial_coef_int(n,k,count+1) * (n - k + count) / count : (long double)(n/count) );
}

constexpr
long double
binomial_coef(const int n, const int k)
{
    return ( k > n - k ? binomial_coef_int(n,n-k,1) : binomial_coef_int(n,k,1.0) );
}

#endif