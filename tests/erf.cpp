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
    constexpr long double x1 = - 1.3;
    long double x2 = x1;

    constexpr long double x3 = 0.0;
    long double x4 = x3;

    constexpr long double x5 = 1.3;
    long double x6 = x5;

    constexpr long double x7 = 2.05;
    long double x8 = x7;

    constexpr long double x9 = 3.1;
    long double x10 = x9;

    std::cout << "\n*** begin erf test ***\n" << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erf(" << x1 <<") = " << std::setprecision(18) << gcem::erf(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_erf(" << x1 <<")  = " << std::setprecision(18) << std::erf(x2) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erf(" << x3 <<") = " << std::setprecision(18) << gcem::erf(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_erf(" << x3 <<")  = " << std::setprecision(18) << std::erf(x4) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erf(" << x5 <<") = " << std::setprecision(18) << gcem::erf(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_erf(" << x5 <<")  = " << std::setprecision(18) << std::erf(x6) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erf(" << x7 <<") = " << std::setprecision(18) << gcem::erf(x7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_erf(" << x7 <<")  = " << std::setprecision(18) << std::erf(x8) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erf(" << x9 <<") = " << std::setprecision(18) << gcem::erf(x9) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_erf(" << x9 <<")  = " << std::setprecision(18) << std::erf(x10) << std::endl;

    std::cout << "\nintegral check:\n" << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erf(" << 2 <<") = " << std::setprecision(18) << gcem::erf(2) << std::endl;

    std::cout << "\n*** end erf test ***\n" << std::endl;

    return 0;
}
