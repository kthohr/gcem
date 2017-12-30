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

// g++-mp-7 -O2 -Wall -std=c++11 -I./../include incomplete_beta_inv.cpp -o incomplete_beta_inv.test -framework Accelerate

#include <cmath>
#include <iostream>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    constexpr long double x = 0.8;

    std::cout << "\n*** begin incomplete_beta_inv test ***\n" << std::endl;

    std::cout << "incomplete_beta_inv(" << 0.9 << "," << 0.9 << "," << x << ") = " << gcem::incomplete_beta_inv(0.9,0.9,x) << std::endl;
    std::cout << std::endl;

    std::cout << "incomplete_beta_inv(" << 1.0 << "," << 1.0 << "," << x << ") = " << gcem::incomplete_beta_inv(1.0,1.0,x) << std::endl;
    std::cout << "incomplete_beta_inv(" << 2.0 << "," << 2.0 << "," << x << ") = " << gcem::incomplete_beta_inv(2.0,2.0,x) << std::endl;
    std::cout << std::endl;

    std::cout << "incomplete_beta_inv(" << 3.0 << "," << 2.0 << "," << x << ") = " << gcem::incomplete_beta_inv(3.0,2.0,x) << std::endl;
    std::cout << "1.0 - incomplete_beta_inv(" << 2.0 << "," << 3.0 << ",1-" << x << ") = " << 1.0L - gcem::incomplete_beta_inv(2.0,3.0,1-x) << std::endl;
    std::cout << std::endl;

    std::cout << "incomplete_beta_inv(" << 3.0 << "," << 2.0 << "," << 0.001 << ") = " << gcem::incomplete_beta_inv(3.0L,2.0L,0.001L) << std::endl;
    std::cout << "incomplete_beta_inv(" << 2.0 << "," << 2.0 << "," << 0.4 << ") = " << gcem::incomplete_beta_inv(3.0L,2.0L,0.4L) << std::endl;

    std::cout << "\n*** end incomplete_beta_inv test ***\n" << std::endl;

    return 0;
}
