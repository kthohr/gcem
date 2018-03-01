/*################################################################################
  ##
  ##   Copyright (C) 2016-2018 Keith O'Hara
  ##
  ##   This file is part of the GCE-Math C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
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
