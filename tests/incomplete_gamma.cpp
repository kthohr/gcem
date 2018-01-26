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
    constexpr long double x1 = 1.0;
    constexpr long double shape_1 = 2.0;
    constexpr long double shape_2 = 1.5;

    std::cout << "\n*** begin incomplete_gamma test ***\n" << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_1 << "," << x1 << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_1,x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_2 << "," << x1 << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_2,x1) << std::endl;
    std::cout << std::endl;

    constexpr long double x2 = 3.0;
    constexpr long double x3 = 5.0;
    constexpr long double x4 = 9.0;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_1 << "," << x2 << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_1,x2) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_1 << "," << x3 << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_1,x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_1 << "," << x4 << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_1,x4) << std::endl;
    std::cout << std::endl;

    constexpr long double x_bad = 0.0;
    constexpr long double shape_bad = 0.0;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_bad << "," << x4 << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_bad,x4) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_1 << "," << x_bad << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_1,x_bad) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_bad << "," << x_bad << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_bad,x_bad) << std::endl;

    std::cout << "\n*** end incomplete_gamma test ***\n" << std::endl;

    return 0;
}
