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
    std::cout << "\n*** begin sin test ***\n" << std::endl;

    constexpr long double x1 = 0.0;
    long double x2 = x1;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sin(" << x1 <<") = " << std::setprecision(18) << gcem::sin(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sin(" << x1 <<")  = " << std::setprecision(18) << std::sin(x2) << std::endl;
    std::cout << std::endl;
    
    constexpr long double x3 = 0.001;
    long double x4 = x3;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3) << "gcem_sin(" << x3 <<") = " << std::setprecision(18) << gcem::sin(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3) << "std_sin(" << x3 <<")  = " << std::setprecision(18) << std::sin(x4) << std::endl;
    std::cout << std::endl;

    constexpr long double x5 = 1.001;
    long double x6 = x5;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sin(" << x5 <<") = " << std::setprecision(18) << gcem::sin(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sin(" << x5 <<")  = " << std::setprecision(18) << std::sin(x6) << std::endl;
    std::cout << std::endl;

    constexpr long double x7 = 1.5;
    long double x8 = x7;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sin(" << x7 <<") = " << std::setprecision(18) << gcem::sin(x7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sin(" << x7 <<")  = " << std::setprecision(18) << std::sin(x8) << std::endl;
    std::cout << std::endl;

    constexpr long double x9 = 11.1;
    long double x10 = x9;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sin(" << x9 <<") = " << std::setprecision(18) << gcem::sin(x9) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sin(" << x9 <<")  = " << std::setprecision(18) << std::sin(x10) << std::endl;
    std::cout << std::endl;

    constexpr long double x11 = 50.0;
    long double x12 = x11;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sin(" << x11 <<") = " << std::setprecision(18) << gcem::sin(x11) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sin(" << x11 <<")  = " << std::setprecision(18) << std::sin(x12) << std::endl;
    std::cout << std::endl;

    constexpr long double x13 = - 1.5;
    long double x14 = x13;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sin(" << x13 <<") = " << std::setprecision(18) << gcem::sin(x13) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sin(" << x13 <<")  = " << std::setprecision(18) << std::sin(x14) << std::endl;

    std::cout << "\n*** end sin test ***\n" << std::endl;

    return 0;
}
