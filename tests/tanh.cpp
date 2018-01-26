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

#include <iostream>
#include <cmath>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    std::cout << "\n*** begin tanh test ***\n" << std::endl;

    constexpr long double x1 = 0.0L;
    long double x2 = x1;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_tanh(" << x1 <<") = " << std::setprecision(18) << gcem::tanh(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_tanh(" << x1 <<")  = " << std::setprecision(18) << std::tanh(x2) << std::endl;
    std::cout << std::endl;

    constexpr long double x3 = 0.001L;
    long double x4 = x3;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_tanh(" << x3 <<") = " << std::setprecision(18) << gcem::tanh(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_tanh(" << x3 <<")  = " << std::setprecision(18) << std::tanh(x4) << std::endl;
    std::cout << std::endl;

    constexpr long double x5 = 0.5L;
    long double x6 = x5;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_tanh(" << x5 <<") = " << std::setprecision(18) << gcem::tanh(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_tanh(" << x5 <<")  = " << std::setprecision(18) << std::tanh(x6) << std::endl;
    std::cout << std::endl;

    constexpr long double x7 = 0.7568025;
    long double x8 = x7;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_tanh(" << x7 <<") = " << std::setprecision(18) << gcem::tanh(x7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_tanh(" << x7 <<")  = " << std::setprecision(18) << std::tanh(x8) << std::endl;
    std::cout << std::endl;

    constexpr long double x9 = 1.0L;
    long double x10 = x9;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_tanh(" << x9 <<") = " << std::setprecision(18) << gcem::tanh(x9) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_tanh(" << x9 <<")  = " << std::setprecision(18) << std::tanh(x10) << std::endl;
    std::cout << std::endl;

    constexpr long double x11 = 5.0L;
    long double x12 = x11;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_tanh(" << x11 <<") = " << std::setprecision(18) << gcem::tanh(x11) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_tanh(" << x11 <<")  = " << std::setprecision(18) << std::tanh(x12) << std::endl;
    std::cout << std::endl;

    constexpr long double x13 = -0.5L;
    long double x14 = x13;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_tanh(" << x13 <<") = " << std::setprecision(18) << gcem::tanh(x13) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_tanh(" << x14 <<")  = " << std::setprecision(18) << std::tanh(x14) << std::endl;

    std::cout << "\n*** end tanh test ***\n" << std::endl;

    return 0;
}
