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
    
    std::cout << "\n*** begin atanh test ***\n" << std::endl;

    constexpr long double x1 = -0.99;
    long double x2 = x1;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_atanh(" << x1 <<") = " << std::setprecision(18) << gcem::atanh(x1) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_atanh(" << x1 <<")  = " << std::setprecision(18) << std::atanh(x2) << std::endl;
    std::cout << std::endl;

    constexpr long double x3 = 0.0L;
    long double x4 = x3;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_atanh(" << x3 <<") = " << std::setprecision(18) << gcem::atanh(x3) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_atanh(" << x3 <<")  = " << std::setprecision(18) << std::atanh(x4) << std::endl;
    std::cout << std::endl;

    constexpr long double x5 = 0.001;
    long double x6 = x5;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_atanh(" << x5 <<") = " << std::setprecision(18) << gcem::atanh(x5) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_atanh(" << x5 <<")  = " << std::setprecision(18) << std::atanh(x6) << std::endl;
    std::cout << std::endl;

    // bad values

    constexpr long double x7 = 1.0L; // bad value
    long double x8 = x7;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_atanh(" << x7 <<") = " << std::setprecision(18) << gcem::atanh(x7) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_atanh(" << x7 <<")  = " << std::setprecision(18) << std::atanh(x8) << std::endl;

    constexpr long double x9 = -1.0L; // bad value
    long double x10 = x9;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_atanh(" << x9 <<") = " << std::setprecision(18) << gcem::atanh(x9) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_atanh(" << x10 <<")  = " << std::setprecision(18) << std::atanh(x10) << std::endl;

    constexpr long double x11 = 1.1L; // illegal value
    long double x12 = x11;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_atanh(" << x11 <<") = " << std::setprecision(18) << gcem::atanh(x11) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "std_atanh(" << x12 <<")  = " << std::setprecision(18) << std::atanh(x12) << std::endl;

    std::cout << "\n*** end atanh test ***\n" << std::endl;

    return 0;
}
