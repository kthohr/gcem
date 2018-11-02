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
    std::cout << "\n*** begin incomplete_beta test ***\n" << std::endl;

    //

    std::function<long double (long double, long double, long double)> test_fn = gcem::incomplete_beta<long double,long double,long double>;
    std::string test_fn_name = "gcem::incomplete_beta";

    //

    static constexpr long double test_vals_1[] = { 0.9L, 0.9L, 1.0L, 2.0L, 3.0L, 2.0L,   3.0L, 2.0L }; // a
    static constexpr long double test_vals_2[] = { 0.9L, 0.9L, 1.0L, 2.0L, 2.0L, 3.0L,   2.0L, 2.0L }; // b
    static constexpr long double test_vals_3[] = { 0.1L, 0.8L, 0.8L, 0.8L, 0.8L, 0.8L, 0.001L, 0.4L }; // x

    static constexpr long double expected_vals[] = { 0.11464699677582491921L,   \
                                                     0.78492840804657726395L,   \
                                                     0.80000000000000004441L,   \
                                                     0.89600000000000001865L,   \
                                                     0.81920000000000003926L,   \
                                                     0.97279999999999999805L,   \
                                                     3.9970000000000084279e-09L,\
                                                     0.35200000000000003508L };
                                                     

    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,0,test_fn,expected_vals[0],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,1,test_fn,expected_vals[1],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,2,test_fn,expected_vals[2],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,3,test_fn,expected_vals[3],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,4,test_fn,expected_vals[4],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,5,test_fn,expected_vals[5],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,6,test_fn,expected_vals[6],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,7,test_fn,expected_vals[7],false," ",3,18,false,false);

    //

    std::cout << "\n*** end incomplete_beta test ***\n" << std::endl;

    return 0;
}
