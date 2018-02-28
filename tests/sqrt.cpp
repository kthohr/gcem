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

// g++-mp-7 -O3 -Wall -std=c++11 -fconstexpr-depth=20 -fconstexpr-steps=1271242 -I./../include sqrt.cpp -o sqrt.test -framework Accelerate

#include <cmath>
#include <iostream>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    constexpr long double x1 = 0.5;
    long double x2 = x1;

    constexpr long double x3 = 1.5;
    long double x4 = x3;

    constexpr long double x5 = 0.00199900000000000208L;
    long double x6 = x5;

    constexpr long double x7 = 41.5;
    long double x8 = x7;

    std::cout << "\n*** begin sqrt test ***\n" << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sqrt(" << x1 <<") = " << std::setprecision(18) << gcem::sqrt(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sqrt(" << x2 <<")  = " << std::setprecision(18) << std::sqrt(x2)  << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sqrt(" << x3 <<") = " << std::setprecision(18) << gcem::sqrt(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sqrt(" << x4 <<")  = " << std::setprecision(18) << std::sqrt(x4)  << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sqrt(" << x5 <<") = " << std::setprecision(18) << gcem::sqrt(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sqrt(" << x6 <<")  = " << std::setprecision(18) << std::sqrt(x6)  << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sqrt(" << x7 <<") = " << std::setprecision(18) << gcem::sqrt(x7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sqrt(" << x8 <<")  = " << std::setprecision(18) << std::sqrt(x8)  << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "\ngcem_sqrt(" << 2 <<") = " << std::setprecision(20) << gcem::sqrt(2.0L) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "sqrt2_cons   = " << std::setprecision(20) << GCEM_SQRT_2 << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "\ngcem_sqrt(" <<  0.0 <<") = " << std::setprecision(20) << gcem::sqrt(0.0L) << std::endl; // should be NaN
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sqrt("   << -1.0 <<") = " << std::setprecision(20) << gcem::sqrt(0.0L) << std::endl; // should be NaN

    std::cout << "\n*** end sqrt test ***\n" << std::endl;

    return 0;
}
