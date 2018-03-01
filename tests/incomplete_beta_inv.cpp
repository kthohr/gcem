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
    constexpr long double x = 0.8;

    std::cout << "\n*** begin incomplete_beta_inv test ***\n" << std::endl;

    std::cout << "incomplete_beta_inv(" << 0.9 << "," << 0.9 << "," << x << ") = " << gcem::incomplete_beta_inv(0.9L,0.9L,x) << std::endl;
    std::cout << std::endl;

    std::cout << "incomplete_beta_inv(" << 1.0 << "," << 1.0 << "," << x << ") = " << gcem::incomplete_beta_inv(1.0L,1.0L,x) << std::endl;
    std::cout << "incomplete_beta_inv(" << 2.0 << "," << 2.0 << "," << x << ") = " << gcem::incomplete_beta_inv(2.0L,2.0L,x) << std::endl;
    std::cout << std::endl;

    std::cout << "incomplete_beta_inv(" << 3.0 << "," << 2.0 << "," << x << ") = " << gcem::incomplete_beta_inv(3.0L,2.0L,x) << std::endl;
    std::cout << "1.0 - incomplete_beta_inv(" << 2.0 << "," << 3.0 << ",1-" << x << ") = " << 1.0L - gcem::incomplete_beta_inv(2.0L,3.0L,1-x) << std::endl;
    std::cout << std::endl;

    std::cout << "incomplete_beta_inv(" << 3.0 << "," << 2.0 << "," << 0.001 << ") = " << gcem::incomplete_beta_inv(3.0L,2.0L,0.001L) << std::endl;
    std::cout << "incomplete_beta_inv(" << 2.0 << "," << 2.0 << "," << 0.4 << ") = " << gcem::incomplete_beta_inv(3.0L,2.0L,0.4L) << std::endl;

    std::cout << "\n*** end incomplete_beta_inv test ***\n" << std::endl;

    return 0;
}
