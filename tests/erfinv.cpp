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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../include erfinv_test.cpp -o erfinv.test -framework Accelerate

#include <cmath>
#include <iostream>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    std::cout << "\nbegin erfinv test\n" << std::endl;

    constexpr long double x = 0.5;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erfinv(gcem_erf(" << x <<")) = " << std::setprecision(18) << gcem::erfinv(gcem::erf(x)) << std::endl;

    constexpr long double x3 = -0.999;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erfinv(" << x3 <<") = " << std::setprecision(18) << gcem::erfinv(x3) << std::endl;

    return 0;
}
