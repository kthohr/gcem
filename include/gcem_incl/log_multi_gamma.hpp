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
 * log multivariate gamma function
 */

#ifndef _gcem_log_multi_gamma_HPP
#define _gcem_log_multi_gamma_HPP

// see https://en.wikipedia.org/wiki/Multivariate_gamma_function

constexpr
long double
log_multi_gamma(const long double a, const int p)
{
    return ( p==1 ? lgamma(a) : ((p-1.0L)/2.0L) * GCEM_LOG_PI + lgamma(a) + log_multi_gamma(a - 0.5L,p-1) );
}

#endif
