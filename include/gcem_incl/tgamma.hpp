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
 * the ('true') gamma function
 *
 * Keith O'Hara
 * 06/28/2017
 *
 * This version:
 * 07/01/2017
 */

#ifndef _gcem_tgamma_HPP
#define _gcem_tgamma_HPP

constexpr
long double
tgamma(const long double x)
{
    return ( x == 1 ? 1 : exp(lgamma(x)));
}

#endif
