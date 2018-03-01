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
    std::cout << "\n*** begin erf_inv test ***\n" << std::endl;

    constexpr long double x = 0.5;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << "gcem_erf_inv(gcem_erf(" << x <<")) = " << std::setprecision(18) << gcem::erf_inv(gcem::erf(x)) << std::endl;

    constexpr long double x3 = -0.999;

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3) << "gcem_erf_inv(" << x3 <<") = " << std::setprecision(18) << gcem::erf_inv(x3) << std::endl;

    std::cout << "\n*** end inv_erf test ***\n" << std::endl;

    return 0;
}
