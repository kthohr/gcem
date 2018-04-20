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
    constexpr int x1 = 5;
    int x2 = x1;

    constexpr long double x3 = 3.10;
    long double x4 = x3;

    std::cout << "\n*** begin factorial test ***\n" << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "gcem_factorial(" << x1 <<     ") = " << std::setprecision(1) << gcem::factorial(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << "    std_tgamma(" << x2 + 1 << ") = " << std::setprecision(1) << std::tgamma(x2+1) << std::endl;
    std::cout << std::endl;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_factorial(" << 7 <<     ") = " << std::setprecision(1) << gcem::factorial(7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "    std_tgamma(" << 8 << ") = " << std::setprecision(1) << std::tgamma(8) << std::endl;
    std::cout << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_factorial(" << x3     << ") = " << std::setprecision(18) << gcem::factorial(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "    std_tgamma(" << x4 + 1 << ") = " << std::setprecision(18) << std::tgamma(x4+1) << std::endl;

    std::cout << "\n*** end factorial test ***\n" << std::endl;

    return 0;
}
