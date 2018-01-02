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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../include asinh.cpp -o asinh.test -framework Accelerate

#include <cmath>
#include <iostream>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    std::cout << "\n*** begin asinh test ***\n" << std::endl;

    constexpr long double x1 = 0.0;
    long double x2 = x1;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_asinh(" << x1 <<") = " << std::setprecision(18) << gcem::asinh(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_asinh(" << x1 <<")  = " << std::setprecision(18) << std::asinh(x2) << std::endl;
    std::cout << std::endl;
    
    constexpr long double x3 = 0.001;
    long double x4 = x3;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3) << "gcem_asinh(" << x3 <<") = " << std::setprecision(18) << gcem::asinh(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3) << "std_asinh(" << x3 <<")  = " << std::setprecision(18) << std::asinh(x4) << std::endl;
    std::cout << std::endl;

    constexpr long double x5 = 1.001;
    long double x6 = x5;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_asinh(" << x5 <<") = " << std::setprecision(18) << gcem::asinh(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_asinh(" << x5 <<")  = " << std::setprecision(18) << std::asinh(x6) << std::endl;
    std::cout << std::endl;

    constexpr long double x7 = 1.5;
    long double x8 = x7;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_asinh(" << x7 <<") = " << std::setprecision(18) << gcem::asinh(x7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_asinh(" << x7 <<")  = " << std::setprecision(18) << std::asinh(x8) << std::endl;
    std::cout << std::endl;

    constexpr long double x9 = 11.1;
    long double x10 = x9;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_asinh(" << x9 <<") = " << std::setprecision(18) << gcem::asinh(x9) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_asinh(" << x9 <<")  = " << std::setprecision(18) << std::asinh(x10) << std::endl;
    std::cout << std::endl;

    constexpr long double x11 = 50.0;
    long double x12 = x11;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_asinh(" << x11 <<") = " << std::setprecision(18) << gcem::asinh(x11) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_asinh(" << x11 <<")  = " << std::setprecision(18) << std::asinh(x12) << std::endl;
    std::cout << std::endl;

    constexpr long double x13 = - 1.5;
    long double x14 = x13;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_asinh(" << x13 <<") = " << std::setprecision(18) << gcem::asinh(x13) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_asinh(" << x13 <<")  = " << std::setprecision(18) << std::asinh(x14) << std::endl;

    std::cout << "\n*** end asinh test ***\n" << std::endl;

    return 0;
}
