/*################################################################################
  ##
  ##   Copyright (C) 2016-2019 Keith O'Hara
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
    std::cout << "\n*** begin incomplete_beta_inv test ***\n" << std::endl;

    //

    std::function<long double (long double, long double, long double)> test_fn = gcem::incomplete_beta_inv<long double,long double,long double>;
    std::string test_fn_name = "gcem::incomplete_beta_inv";

    //

    static constexpr long double test_vals_1[] = { 0.9L, 0.9L, 1.0L, 2.0L, 3.0L, 2.0L,   3.0L, 2.0L }; // a
    static constexpr long double test_vals_2[] = { 0.9L, 0.9L, 1.0L, 2.0L, 2.0L, 3.0L,   2.0L, 2.0L }; // b
    static constexpr long double test_vals_3[] = { 0.1L, 0.8L, 0.8L, 0.8L, 0.8L, 0.8L, 0.001L, 0.4L }; // x

    static constexpr long double expected_vals[] = { 0.085977260425697907276L, \
                                                     0.81533908558467627081L,  \
                                                     0.80000000000000004441L,  \
                                                     0.71285927458325959449L,  \
                                                     0.78768287172204876079L,  \
                                                     0.58245357452433332845L,  \
                                                     0.064038139102833388505L, \
                                                     0.43293107714773171324L };
                                                     

    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,0,test_fn,expected_vals[0],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,1,test_fn,expected_vals[1],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,2,test_fn,expected_vals[2],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,3,test_fn,expected_vals[3],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,4,test_fn,expected_vals[4],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,5,test_fn,expected_vals[5],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,6,test_fn,expected_vals[6],true," ",3,18,false,false);
    PRINT_TEST_3_EXPECT(test_fn_name,test_vals_1,test_vals_2,test_vals_3,7,test_fn,expected_vals[7],false," ",3,18,false,false);

    //

    std::cout << "\n*** end incomplete_beta_inv test ***\n" << std::endl;

    return 0;
}
