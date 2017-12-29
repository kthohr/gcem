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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../include atanh.cpp -o atanh.test -framework Accelerate

#include <cmath>
#include <iostream>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    
    std::cout << "\n*** begin atanh test ***\n" << std::endl;

    constexpr long double x1 = -0.99;
    long double x2 = x1;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_atanh(" << x1 <<") = " << std::setprecision(18) << gcem::atanh(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_atanh(" << x1 <<")  = " << std::setprecision(18) << std::atanh(x2) << std::endl;
    std::cout << std::endl;

    constexpr long double x3 = 0.0L;
    long double x4 = x3;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_atanh(" << x3 <<") = " << std::setprecision(18) << gcem::atanh(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_atanh(" << x3 <<")  = " << std::setprecision(18) << std::atanh(x4) << std::endl;
    std::cout << std::endl;

    constexpr long double x5 = 0.001;
    long double x6 = x5;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_atanh(" << x5 <<") = " << std::setprecision(18) << gcem::atanh(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_atanh(" << x5 <<")  = " << std::setprecision(18) << std::atanh(x6) << std::endl;
    std::cout << std::endl;

    constexpr long double x7 = 1.1L; // illegal value
    long double x8 = x7;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_atanh(" << x7 <<") = " << std::setprecision(18) << gcem::atanh(x7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_atanh(" << x7 <<")  = " << std::setprecision(18) << std::atanh(x8) << std::endl;

    std::cout << "\n*** end atanh test ***\n" << std::endl;

    return 0;
}
