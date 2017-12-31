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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../include atan.cpp -o atan.test -framework Accelerate

#include <iostream>
#include <cmath>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    std::cout << "\n*** begin atan test ***\n" << std::endl;

    constexpr long double x1 = 0.0L;
    long double x2 = x1;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x1 <<") = " << std::setprecision(18) << gcem::atan(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x1 <<")  = " << std::setprecision(18) << std::atan(x2) << std::endl;
    std::cout << std::endl;

    constexpr long double x3 = 0.001L;
    long double x4 = x3;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x3 <<") = " << std::setprecision(18) << gcem::atan(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x3 <<")  = " << std::setprecision(18) << std::atan(x4) << std::endl;
    std::cout << std::endl;

    constexpr long double x5 = 0.49L;
    long double x6 = x5;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x5 <<") = " << std::setprecision(18) << gcem::atan(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x5 <<")  = " << std::setprecision(18) << std::atan(x6) << std::endl;
    std::cout << std::endl;

    constexpr long double x7 = -0.5L;
    long double x8 = x7;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x7 <<") = " << std::setprecision(18) << gcem::atan(x7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x7 <<")  = " << std::setprecision(18) << std::atan(x8) << std::endl;
    std::cout << std::endl;

    constexpr long double x9 = 0.7568025;
    long double x10 = x9;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x9 <<") = " << std::setprecision(18) << gcem::atan(x9) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x9 <<")  = " << std::setprecision(18) << std::atan(x10) << std::endl;
    std::cout << std::endl;

    constexpr long double x41 = 0.99;
    long double x42 = x41;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x41 <<") = " << std::setprecision(18) << gcem::atan(x41) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x41 <<")  = " << std::setprecision(18) << std::atan(x42) << std::endl;
    std::cout << std::endl;

    constexpr long double x43 = 1.49;
    long double x44 = x43;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x43 <<") = " << std::setprecision(18) << gcem::atan(x43) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x43 <<")  = " << std::setprecision(18) << std::atan(x44) << std::endl;
    std::cout << std::endl;

    constexpr long double x11 = 1.99L;
    long double x12 = x11;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x11 <<") = " << std::setprecision(18) << gcem::atan(x11) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x11 <<")  = " << std::setprecision(18) << std::atan(x12) << std::endl;
    std::cout << std::endl;

    constexpr long double x45 = 2.49;
    long double x46 = x45;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x45 <<") = " << std::setprecision(18) << gcem::atan(x45) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x45 <<")  = " << std::setprecision(18) << std::atan(x46) << std::endl;
    std::cout << std::endl;

    constexpr long double x27 = 2.51L;
    long double x28 = x27;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x27 <<") = " << std::setprecision(18) << gcem::atan(x27) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x28 <<")  = " << std::setprecision(18) << std::atan(x28) << std::endl;
    std::cout << std::endl;

    constexpr long double x13 = 3.99L;
    long double x14 = x13;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x13 <<") = " << std::setprecision(18) << gcem::atan(x13) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x13 <<")  = " << std::setprecision(18) << std::atan(x14) << std::endl;
    std::cout << std::endl;

    constexpr long double x15 = 7.0L;
    long double x16 = x15;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x15 <<") = " << std::setprecision(18) << gcem::atan(x15) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x15 <<")  = " << std::setprecision(18) << std::atan(x16) << std::endl;
    std::cout << std::endl;

    constexpr long double x17 = 11.0L;
    long double x18 = x17;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x17 <<") = " << std::setprecision(18) << gcem::atan(x17) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x17 <<")  = " << std::setprecision(18) << std::atan(x18) << std::endl;
    std::cout << std::endl;

    constexpr long double x19 = 25.0L;
    long double x20 = x19;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x19 <<") = " << std::setprecision(18) << gcem::atan(x19) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x19 <<")  = " << std::setprecision(18) << std::atan(x20) << std::endl;
    std::cout << std::endl;

    constexpr long double x21 = 101.0L;
    long double x22 = x21;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x21 <<") = " << std::setprecision(18) << gcem::atan(x21) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x21 <<")  = " << std::setprecision(18) << std::atan(x22) << std::endl;
    std::cout << std::endl;

    constexpr long double x23 = 900.0L;
    long double x24 = x23;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x23 <<") = " << std::setprecision(18) << gcem::atan(x23) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x23 <<")  = " << std::setprecision(18) << std::atan(x24) << std::endl;
    std::cout << std::endl;

    constexpr long double x25 = 1001.0L;
    long double x26 = x25;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_atan(" << x25 <<") = " << std::setprecision(18) << gcem::atan(x25) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "std_atan(" << x25 <<")  = " << std::setprecision(18) << std::atan(x26) << std::endl;

    std::cout << "\n*** end atan test ***\n" << std::endl;

    return 0;
}
