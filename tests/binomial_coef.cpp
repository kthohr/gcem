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

// g++-mp-7 -O3 -Wall -std=c++11 -I./../include -I/opt/local/include binomial_coef.cpp -o binomial_coef.test -framework Accelerate

#include <iostream>
#include <cmath>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    constexpr int n = 5;
    constexpr int k = 2;

    constexpr long double result = gcem::binomial_coef(n,k);

    std::cout << "\nbegin binomial_coef test\n" << std::endl;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_binomial_coef(" << n <<"," << k << ") = " << std::setprecision(18) << result << std::endl;

    std::cout << "\nend binomial_coef test" << std::endl;

    return 0;
}
