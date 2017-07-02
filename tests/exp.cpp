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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../include exp_test.cpp -o exp.test -framework Accelerate

#include <cmath>
#include <iostream>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    constexpr long double x1 = 1.75;
    long double x2 = x1;

    constexpr long double x3 = -4.0;
    long double x4 = x3;

    constexpr long double x5 = -40.0;
    long double x6 = x5;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "gcem_exp(" << x1 <<") = " << std::setprecision(18) << gcem::exp(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "std_exp(" << x2 <<")  = " << std::setprecision(18) << std::exp(x2) << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "gcem_exp(" << x3 <<") = " << std::setprecision(18) << gcem::exp(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "std_exp(" << x4 <<")  = " << std::setprecision(18) << std::exp(x4) << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "gcem_exp(" << x5 <<") = " << std::setprecision(18) << gcem::exp(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "std_exp(" << x6 <<")  = " << std::setprecision(18) << std::exp(x6) << std::endl;

    return 0;
}
