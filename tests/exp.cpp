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
    constexpr long double x1 = 1.75;
    long double x2 = x1;

    constexpr long double x3 = 2.10;
    long double x4 = x3;

    constexpr long double x5 = -4.0;
    long double x6 = x5;

    constexpr long double x7 = -40.0;
    long double x8 = x7;

    constexpr long double x9 = 0.0001;
    long double x10 = x9;

    constexpr long double x11 = 1.9991;
    long double x12 = x11;

    std::cout << "\n*** begin exp test ***\n" << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "gcem_exp(" << x1 <<") = " << std::setprecision(18) << gcem::exp(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "std_exp(" << x2 <<")  = " << std::setprecision(18) << std::exp(x2) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "gcem_exp(" << x3 <<") = " << std::setprecision(18) << gcem::exp(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "std_exp(" << x4 <<")  = " << std::setprecision(18) << std::exp(x4) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "gcem_exp(" << x5 <<") = " << std::setprecision(18) << gcem::exp(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "std_exp(" << x6 <<")  = " << std::setprecision(18) << std::exp(x6) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "gcem_exp(" << x7 <<") = " << std::setprecision(18) << gcem::exp(x7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "std_exp(" << x8 <<")  = " << std::setprecision(18) << std::exp(x8) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "gcem_exp(" << x9 <<") = " << std::setprecision(18) << gcem::exp(x9) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "std_exp(" << x10 <<")  = " << std::setprecision(18) << std::exp(x10) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "gcem_exp(" << x11 <<") = " << std::setprecision(18) << gcem::exp(x11) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "std_exp(" << x12 <<")  = " << std::setprecision(18) << std::exp(x12) << std::endl;

    std::cout << "\n*** end exp test ***\n" << std::endl;

    return 0;
}
