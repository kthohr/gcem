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
    constexpr long double x1 = 0.3;
    double x2 = x1;
    constexpr long double shape = 1.5;
    constexpr long double scale = 2;

    std::cout << "\nbegin incomplete_gamma_inv test\n" << std::endl;

    std::cout << "incomplete_gamma_inv: " << scale*gcem::incomplete_gamma_inv(shape,x1) << std::endl;

    // for coverage:

    gcem::incomplete_gamma_inv(2.0,0.7);
    gcem::incomplete_gamma_inv(0.7,x2);

    return 0;
}
