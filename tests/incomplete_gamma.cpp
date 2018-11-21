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
    std::cout << "\n*** begin incomplete_gamma test ***\n" << std::endl;

    //

    std::function<long double (long double, long double)> test_fn = gcem::incomplete_gamma<long double,long double>;
    std::string test_fn_name = "gcem::incomplete_gamma";

    //

    static constexpr long double test_vals_1[] = { \
         2.0L,  1.5L,  2.0L,   2.0L,   2.0L,   0.0L,   2.0L,   0.0L,  11.5L,  15.5L,  19.0L,   20.0L,\
        38.0L, 56.0L, 98.0L, 102.0L, 298.0L, 302.0L, 498.0L, 502.0L, 798.0L, 801.0L, 997.0L, 1005.0L, -0.1L }; // shape
    static constexpr long double test_vals_2[] = { \
         1.0L,  1.0L,  3.0L,   5.0L,   9.0L,   9.0L,   0.0L,   0.0L,  11.0L,  18.0L,  18.0L,   19.0L,\
        39.0L, 55.0L, 99.0L, 101.0L, 297.0L, 301.0L, 497.0L, 501.0L, 799.0L, 800.0L, 999.0L, 1001.0L, 0.0L }; // x

    static constexpr long double expected_vals[] = { 0.26424111765711527644L,
                                                     0.42759329552912134220L,
                                                     0.80085172652854419439L,
                                                     0.95957231800548714595L,
                                                     0.99876590195913317327L,
                                                     1.0L,
                                                     0.0L,
                                                     0.0L,
                                                     0.47974821959920432857L,
                                                     0.75410627202774938027L,
                                                     0.43775501395596266851L,
                                                     0.43939261060849132967L, 
                                                     0.58504236243630125536L,
                                                     0.46422093592347296598L,
                                                     0.55342727426212001696L,
                                                     0.47356929040257916830L,
                                                     0.48457398488934400049L,
                                                     0.48467673854389853316L,
                                                     0.48807306199561317772L,
                                                     0.48812074555706047585L,
                                                     0.51881664512582725823L,
                                                     0.49059834200005758564L,
                                                     0.52943655952003709775L,
                                                     0.45389544705967349580L };

    //

    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,0,test_fn,expected_vals[0],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,1,test_fn,expected_vals[1],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,2,test_fn,expected_vals[2],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,3,test_fn,expected_vals[3],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,4,test_fn,expected_vals[4],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,5,test_fn,expected_vals[5],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,6,test_fn,expected_vals[6],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,7,test_fn,expected_vals[7],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,8,test_fn,expected_vals[8],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,9,test_fn,expected_vals[9],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,10,test_fn,expected_vals[10],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,11,test_fn,expected_vals[11],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,12,test_fn,expected_vals[12],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,13,test_fn,expected_vals[13],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,14,test_fn,expected_vals[14],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,15,test_fn,expected_vals[15],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,16,test_fn,expected_vals[16],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,17,test_fn,expected_vals[17],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,18,test_fn,expected_vals[18],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,19,test_fn,expected_vals[19],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,20,test_fn,expected_vals[20],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,21,test_fn,expected_vals[21],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,22,test_fn,expected_vals[22],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,23,test_fn,expected_vals[23],true,"",3,18,false,false);
    PRINT_TEST_2_EXPECT(test_fn_name,test_vals_1,test_vals_2,24,test_fn,0.0L,true,"",3,18,false,true);

    //

    std::cout << "\n*** end incomplete_gamma test ***\n" << std::endl;

    return 0;
}
