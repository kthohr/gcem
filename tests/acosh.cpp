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
    
    std::cout << "\n*** begin acosh test ***\n" << std::endl;

    constexpr long double x1 = 1.001;
    long double x2 = x1;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_acosh(" << x1 <<") = " << std::setprecision(18) << gcem::acosh(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_acosh(" << x1 <<")  = " << std::setprecision(18) << std::acosh(x2) << std::endl;
    std::cout << std::endl;

    constexpr long double x3 = 1.5;
    long double x4 = x3;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_acosh(" << x3 <<") = " << std::setprecision(18) << gcem::acosh(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_acosh(" << x3 <<")  = " << std::setprecision(18) << std::acosh(x4) << std::endl;
    std::cout << std::endl;

    constexpr long double x5 = 11.1;
    long double x6 = x5;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_acosh(" << x5 <<") = " << std::setprecision(18) << gcem::acosh(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_acosh(" << x5 <<")  = " << std::setprecision(18) << std::acosh(x6) << std::endl;
    std::cout << std::endl;

    constexpr long double x7 = 50.0;
    long double x8 = x7;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_acosh(" << x7 <<") = " << std::setprecision(18) << gcem::acosh(x7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_acosh(" << x7 <<")  = " << std::setprecision(18) << std::acosh(x8) << std::endl;

    std::cout << "\n*** end acosh test ***\n" << std::endl;

    return 0;
}
