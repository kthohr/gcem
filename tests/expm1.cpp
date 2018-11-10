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
    std::cout << "\n*** begin expm1 test ***\n" << std::endl;

    //

    std::function<long double (long double)> test_fn = gcem::expm1<long double>;
    std::string test_fn_name = "gcem::expm1";

    std::function<long double (long double)> std_fn  = [] (long double x) -> long double { return std::expm1(x); };
    std::string std_fn_name = "std::expm1";

    //

    static constexpr long double test_vals[] = { 1.0L, 0.0L, 1e-04L, -1e-04L, 1e-05L, 1e-06L, 1e-22L };

    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,0,test_fn,std_fn,true," ",5,18,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,1,test_fn,std_fn,true," ",5,18,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,2,test_fn,std_fn,true," ",5,18,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,3,test_fn,std_fn,true," ",5,18,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,4,test_fn,std_fn,true," ",5,18,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,5,test_fn,std_fn,true," ",5,18,false,false);
    PRINT_TEST_1_COMPARE(test_fn_name,std_fn_name,test_vals,6,test_fn,std_fn,false," ",5,18,false,false);

    //

    std::cout << "\n*** end expm1 test ***\n" << std::endl;

    return 0;
}
