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

// g++-mp-7 -O3 -Wall -std=c++11 -fconstexpr-depth=20 -fconstexpr-steps=1271242 -I./../include sqrt.cpp -o sqrt.test -framework Accelerate

#include <cmath>
#include <iostream>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    constexpr long double x1 = 0.5;
    long double x2 = x1;

    constexpr long double x3 = 1.5;
    long double x4 = x3;

    constexpr long double x5 = 0.00199900000000000208L;
    long double x6 = x5;

    constexpr long double x7 = 41.5;
    long double x8 = x7;

    std::cout << "\n*** begin sqrt test ***\n" << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sqrt(" << x1 <<") = " << std::setprecision(18) << gcem::sqrt(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sqrt(" << x2 <<")  = " << std::setprecision(18) << std::sqrt(x2)  << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sqrt(" << x3 <<") = " << std::setprecision(18) << gcem::sqrt(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sqrt(" << x4 <<")  = " << std::setprecision(18) << std::sqrt(x4)  << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sqrt(" << x5 <<") = " << std::setprecision(18) << gcem::sqrt(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sqrt(" << x6 <<")  = " << std::setprecision(18) << std::sqrt(x6)  << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sqrt(" << x7 <<") = " << std::setprecision(18) << gcem::sqrt(x7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_sqrt(" << x8 <<")  = " << std::setprecision(18) << std::sqrt(x8)  << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "\ngcem_sqrt(" << 2 <<") = " << std::setprecision(20) << gcem::sqrt(2.0L) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "sqrt2_cons   = " << std::setprecision(20) << GCEM_SQRT_2 << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "\ngcem_sqrt(" <<  0.0 <<") = " << std::setprecision(20) << gcem::sqrt(0.0L) << std::endl; // should be 0
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_sqrt("   << -1.0 <<") = " << std::setprecision(20) << gcem::sqrt(-1.0L) << std::endl; // should be NaN

    std::cout << "\n*** end sqrt test ***\n" << std::endl;

    return 0;
}
