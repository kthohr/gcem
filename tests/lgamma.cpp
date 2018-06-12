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
    std::cout << "\n*** begin lgamma test ***\n" << std::endl;

    constexpr long double x = 1.5;
    long double x2 = x;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_lgamma(" << x <<") = " << std::setprecision(18) << gcem::lgamma(x) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_lgamma(" << x <<")  = " << std::setprecision(18) << std::lgamma(x2) << std::endl;
    std::cout << std::endl;

    constexpr long double x3 = 0.7;
    long double x4 = x3;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_lgamma(" << x3 <<") = " << std::setprecision(18) << gcem::lgamma(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_lgamma(" << x4 <<")  = " << std::setprecision(18) << std::lgamma(x4) << std::endl;
    std::cout << std::endl;

    constexpr long double x5 = 1.0;
    long double x6 = x5;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_lgamma(" << x5 <<") = " << std::setprecision(18) << gcem::lgamma(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_lgamma(" << x6 <<")  = " << std::setprecision(18) << std::lgamma(x6) << std::endl;
    std::cout << std::endl;

    constexpr long double x7 = 0.0;
    long double x8 = x7;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_lgamma(" << x7 <<") = " << std::setprecision(18) << gcem::lgamma(x7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_lgamma(" << x8 <<")  = " << std::setprecision(18) << std::lgamma(x8) << std::endl;

    std::cout << "\n*** end lgamma test ***\n" << std::endl;

    return 0;
}
