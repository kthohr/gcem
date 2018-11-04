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
    std::cout << "\n*** begin atan2 test ***\n" << std::endl;

    //

    std::function<long double (long double,long double)> test_fn = gcem::atan2<long double,long double>;
    std::string test_fn_name = "gcem::atan2";

    std::function<long double (long double, long double)> std_fn  = [] (long double x, long double y) -> long double { return std::atan2(x,y); };
    std::string std_fn_name = "std::atan2";

    //

    static constexpr long double test_vals_1[] = { 0.0L, -0.0L, 0.0L, -0.0L, 0.2L, -0.2L, 0.001L, 0.49L, -0.5L,  0.5L, -0.5L, \
                                                   9.6L, 1.0L, 0.0L, -1.0L,  0.0L, 1.0L, -5.0L, -1000.0L,  0.1337L };

    static constexpr long double test_vals_2[] = { 0.0L, 0.0L, -0.0L, -0.0L, 0.0L,  0.0L, 0.001L, 0.49L, -0.5L, -0.5L,  0.5L, \
                                                   8.4L, 0.0L, 1.0L,  0.0L, -1.0L, 3.0L,  2.5L,  -0.001L, -123456.0L };

    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,0,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,1,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,2,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,3,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,4,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,5,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,6,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,7,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,8,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,9,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,10,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,11,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,12,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,13,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,14,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,15,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,16,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,17,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,18,test_fn,std_fn,true," ",6,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,19,test_fn,std_fn,false," ",6,18,false,false);

    std::cout << "\n*** end atan2 test ***\n" << std::endl;

    return 0;
}
