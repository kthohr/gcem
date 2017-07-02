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

// g++-mp-5 -O2 -Wall -std=c++11 -I./../include incomplete_gamma_inv_test.cpp -o incomplete_gamma_inv.test -framework Accelerate

#include <cmath>
#include <iostream>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    double ret_val;
    double x = 0.5;
    double shape = 2;
    double scale = 2;
    gcem::incomplete_gamma_inv(shape,x,ret_val);

    std::cout << "\nbegin incomplete_gamma_inv test\n" << std::endl;

    std::cout << "incomplete_gamma_inv: " << scale*ret_val << std::endl;

    return 0;
}
