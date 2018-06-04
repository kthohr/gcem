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
    std::cout << std::endl;

    //

    constexpr long double x_med_1 = 11.0;
    constexpr long double shape_med_1 = 11.5;

    constexpr long double x_med_2 = 18.0;
    constexpr long double shape_med_2 = 15.5;

    constexpr long double x_med_3 = 18.0;
    constexpr long double shape_med_3 = 19.0;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_med_1  << "," << x_med_1  << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_med_1, x_med_1)  << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_med_2  << "," << x_med_2  << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_med_2, x_med_2)  << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_med_3  << "," << x_med_3  << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_med_3, x_med_3)  << std::endl;
    std::cout << std::endl;

    //

    constexpr long double x_big_1 = 19.0;
    constexpr long double shape_big_1 = 20.0;

    constexpr long double x_big_2 = 39.0;
    constexpr long double shape_big_2 = 38.0;

    constexpr long double x_big_3 = 55.0;
    constexpr long double shape_big_3 = 56.0;

    constexpr long double x_big_4 = 99.0;
    constexpr long double shape_big_4 = 98.0;

    constexpr long double x_big_5 = 101.0;
    constexpr long double shape_big_5 = 102.0;

    constexpr long double x_big_6 = 297.0;
    constexpr long double shape_big_6 = 298.0;

    constexpr long double x_big_7 = 301.0;
    constexpr long double shape_big_7 = 302.0;

    constexpr long double x_big_8 = 497.0;
    constexpr long double shape_big_8 = 498.0;

    constexpr long double x_big_9 = 501.0;
    constexpr long double shape_big_9 = 502.0;

    constexpr long double x_big_10 = 799.0;
    constexpr long double shape_big_10 = 798.0;

    constexpr long double x_big_11 = 800.0;
    constexpr long double shape_big_11 = 801.0;

    constexpr long double x_big_12 = 999.0;
    constexpr long double shape_big_12 = 997.0;

    constexpr long double x_big_13 = 1001.0;
    constexpr long double shape_big_13 = 1005.0;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_big_1  << "," << x_big_1  << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_big_1, x_big_1)  << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_big_2  << "," << x_big_2  << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_big_2, x_big_2)  << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_big_3  << "," << x_big_3  << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_big_3, x_big_3)  << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_big_4  << "," << x_big_4  << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_big_4, x_big_4)  << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_big_5  << "," << x_big_5  << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_big_5, x_big_5)  << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_big_6  << "," << x_big_6  << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_big_6, x_big_6)  << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_big_7  << "," << x_big_7  << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_big_7, x_big_7)  << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_big_8  << "," << x_big_8  << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_big_8, x_big_8)  << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_big_9  << "," << x_big_9  << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_big_9, x_big_9)  << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_big_10 << "," << x_big_10 << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_big_10,x_big_10) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_big_11 << "," << x_big_11 << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_big_11,x_big_11) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_big_12 << "," << x_big_12 << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_big_12,x_big_12) << std::endl;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_inc_gamma(" << shape_big_13 << "," << x_big_13 << ") = " << std::setprecision(18) << gcem::incomplete_gamma(shape_big_13,x_big_13) << std::endl;

    std::cout << "\n*** end incomplete_gamma test ***\n" << std::endl;

    return 0;
}
