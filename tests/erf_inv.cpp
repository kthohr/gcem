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

#include <cmath>
#include <iostream>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    std::cout << "\nbegin erf_inv test\n" << std::endl;

    constexpr long double x = 0.5;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erf_inv(gcem_erf(" << x <<")) = " << std::setprecision(18) << gcem::erf_inv(gcem::erf(x)) << std::endl;

    constexpr long double x3 = -0.999;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3) << "gcem_erf_inv(" << x3 <<") = " << std::setprecision(18) << gcem::erf_inv(x3) << std::endl;

    return 0;
}
