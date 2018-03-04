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

#include <iostream>
#include <cmath>
#include <iomanip>
#include "gcem.hpp"

int main()
{
    constexpr int n = 5;
    constexpr int k = 2;

    // long double result = gcem::binomial_coef(n,k);

    std::cout << "\nbegin binomial_coef test\n" << std::endl;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_binomial_coef(" << 0 <<"," << 0 << ") = " << std::setprecision(2) << gcem::binomial_coef(0U,0U) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_binomial_coef(" << 0 <<"," << 1 << ") = " << std::setprecision(2) << gcem::binomial_coef(0U,1U) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_binomial_coef(" << 1 <<"," << 0 << ") = " << std::setprecision(2) << gcem::binomial_coef(1U,0U) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << "gcem_binomial_coef(" << n <<"," << k << ") = " << std::setprecision(2) << gcem::binomial_coef(n,k) << std::endl;

    std::cout << "\nend binomial_coef test" << std::endl;

    return 0;
}
