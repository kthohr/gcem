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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../include incomplete_gamma_inv.cpp -o incomplete_gamma_inv.test -framework Accelerate

#include <cmath>
#include <iostream>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    constexpr long double x1 = 0.3;
    double x2 = x1;
    constexpr long double shape = 1.5;
    constexpr long double scale = 2;

    std::cout << "\nbegin incomplete_gamma_inv test\n" << std::endl;

    std::cout << "incomplete_gamma_inv: " << scale*gcem::incomplete_gamma_inv(shape,x1) << std::endl;


    gcem::incomplete_gamma_inv(2,0.7);  // for coverage
    gcem::incomplete_gamma_inv(0.7,x2); // for coverage

    return 0;
}
