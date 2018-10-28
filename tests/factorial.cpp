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

#define TEST_ERR_TOL 1e-02
#include "gcem_tests.hpp"

int main()
{
    std::cout << "\n*** begin factorial test ***\n" << std::endl;

    //

    std::function<long double (long double)> test_fn_int = [] (long double x) -> long double \
        { return static_cast<long double>(gcem::factorial<size_t>(size_t(x))); };
    std::function<long double (long double)> test_fn_dbl = gcem::factorial<long double>;
    std::string test_fn_name = "gcem::factorial";

    std::function<long double (long double)> std_fn  = [] (long double x) -> long double { return std::tgamma(x+1); };
    std::string std_fn_name = "std::tgamma";

    //

    static constexpr long double test_vals[] = { 3.1L, 5.0L, 7.0L, 9.0L, 10.0L, 11.0L, 12.0L, 13.0L, 14.0L, 15.0L, 16.0L };

    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,0,test_fn_dbl,std_fn,true,"    ",2,18,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,1,test_fn_int,std_fn,true,"    ",2,2,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,2,test_fn_dbl,std_fn,true,"    ",2,2,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,3,test_fn_int,std_fn,true,"    ",2,2,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,4,test_fn_dbl,std_fn,true,"    ",2,2,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,5,test_fn_int,std_fn,true,"    ",2,2,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,6,test_fn_dbl,std_fn,true,"    ",2,2,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,7,test_fn_int,std_fn,true,"    ",2,2,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,8,test_fn_dbl,std_fn,true,"    ",2,2,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,9,test_fn_dbl,std_fn,true,"    ",2,2,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,10,test_fn_int,std_fn,false,"    ",2,2,false,false);

    //
    
    std::cout << "\n*** end factorial test ***\n" << std::endl;

    return 0;
}
