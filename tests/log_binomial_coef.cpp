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

#include "gcem_tests.hpp"

int main()
{
    std::cout << "\n*** begin log_binomial_coef test ***\n" << std::endl;

    //

    std::function<long double (long double, long double)> test_fn = gcem::log_binomial_coef<long double, long double>;
    std::string test_fn_name = "gcem::log_binomial_coef";

    //

    static constexpr long double test_vals_1[] = { 0.0L, 0.0L, 1.0L, 1.0L, 5.0L, 10.0L, 10.0L, 10.0L };
    static constexpr long double test_vals_2[] = { 0.0L, 1.0L, 0.0L, 1.0L, 2.0L, 8.0L,  9.0L,  10.0L };

    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,0,test_fn,0.0L,true,"",2,2,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,1,test_fn,.0L,true,"",2,2,true,false); // ignore input value
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,2,test_fn,0.0L,true,"",2,2,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,3,test_fn,0.0L,true,"",2,2,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,4,test_fn,std::log(10.0L),true,"",2,2,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,5,test_fn,std::log(45.0L),true,"",2,2,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,6,test_fn,std::log(10.0L),true,"",2,2,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,7,test_fn,0.0L,false,"",2,2,false,false);

    //

    std::cout << "\n*** end log_binomial_coef test ***\n" << std::endl;

    return 0;
}
