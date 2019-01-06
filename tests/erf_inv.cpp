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
    std::cout << "\n*** begin erf_inv test ***\n" << std::endl;

    //

    std::function<long double (long double)> test_fn = gcem::erf_inv<long double>;
    std::string test_fn_name = "gcem::erf_inv";

    //

    static constexpr long double test_vals[] = { -0.999977909503001415L, \
                                                 -0.999593047982555041L, \
                                                 -0.997154845031177802L, \
                                                 -0.996258096044456873L, \
                                                 -0.934007944940652437L, \
                                                  0.0L,                  \
                                                  0.934007944940652437L, \
                                                  0.996258096044456873L, \
                                                  0.997154845031177802L, \
                                                  0.999593047982555041L, \
                                                  0.999988351342632800L};

    static constexpr long double results[] = { -3.0L, -2.5L, -2.11L, -2.05L, -1.3L, 0.0L, 1.3L, 2.05L, 2.11L, 2.5L, 3.1L };

    PRINT_TEST_1_EXPECT(test_fn_name,test_vals,0,test_fn,results[0],true," ",6,18,false,false);
    PRINT_TEST_1_EXPECT(test_fn_name,test_vals,1,test_fn,results[1],true," ",6,18,false,false);
    PRINT_TEST_1_EXPECT(test_fn_name,test_vals,2,test_fn,results[2],true," ",6,18,false,false);
    PRINT_TEST_1_EXPECT(test_fn_name,test_vals,3,test_fn,results[3],true," ",6,18,false,false);
    PRINT_TEST_1_EXPECT(test_fn_name,test_vals,4,test_fn,results[4],true," ",6,18,false,false);
    PRINT_TEST_1_EXPECT(test_fn_name,test_vals,5,test_fn,results[5],true," ",6,18,false,false);
    PRINT_TEST_1_EXPECT(test_fn_name,test_vals,6,test_fn,results[6],true," ",6,18,false,false);
    PRINT_TEST_1_EXPECT(test_fn_name,test_vals,7,test_fn,results[7],true," ",6,18,false,false);
    PRINT_TEST_1_EXPECT(test_fn_name,test_vals,8,test_fn,results[8],true," ",6,18,false,false);
    PRINT_TEST_1_EXPECT(test_fn_name,test_vals,9,test_fn,results[9],true," ",6,18,false,false);
    PRINT_TEST_1_EXPECT(test_fn_name,test_vals,10,test_fn,results[10],false," ",6,18,false,false);

    //

    std::cout << "\n*** end inv_erf test ***\n" << std::endl;

    return 0;
}
