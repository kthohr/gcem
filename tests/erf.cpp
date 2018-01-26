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
    constexpr long double x1 = - 1.3;
    long double x2 = x1;

    constexpr long double x3 = 0.0;
    long double x4 = x3;

    constexpr long double x5 = 1.3;
    long double x6 = x5;

    constexpr long double x7 = 2.05;
    long double x8 = x7;

    constexpr long double x9 = 3.1;
    long double x10 = x9;

    std::cout << "\n*** begin erf test ***\n" << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erf(" << x1 <<") = " << std::setprecision(18) << gcem::erf(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_erf(" << x1 <<")  = " << std::setprecision(18) << std::erf(x2) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erf(" << x3 <<") = " << std::setprecision(18) << gcem::erf(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_erf(" << x3 <<")  = " << std::setprecision(18) << std::erf(x4) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erf(" << x5 <<") = " << std::setprecision(18) << gcem::erf(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_erf(" << x5 <<")  = " << std::setprecision(18) << std::erf(x6) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erf(" << x7 <<") = " << std::setprecision(18) << gcem::erf(x7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_erf(" << x7 <<")  = " << std::setprecision(18) << std::erf(x8) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erf(" << x9 <<") = " << std::setprecision(18) << gcem::erf(x9) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_erf(" << x9 <<")  = " << std::setprecision(18) << std::erf(x10) << std::endl;

    std::cout << "\n*** end erf test ***\n" << std::endl;

    return 0;
}
