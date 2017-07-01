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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../include atan_test.cpp -o atan.test -framework Accelerate

#include <math.h>
#include <iostream>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    constexpr double x = 0.7568025;
    double x2 = x;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x <<")  = " << std::setprecision(18) << gcem::atan(x) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x <<")   = " << std::setprecision(18) << std::atan(x2) << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << -x <<") = " << std::setprecision(18) << gcem::atan(-x) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << -x <<")  = " << std::setprecision(18) << std::atan(-x2) << std::endl;

    return 0;
}
