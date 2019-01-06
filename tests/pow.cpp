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
    std::cout << "\n*** begin pow test ***\n" << std::endl;

    //

    std::function<long double (long double, long double)> test_fn_int = [] (long double x, long double y) -> long double \
        { return gcem::pow<long double>(x,size_t(y)); };

    std::function<long double (long double, long double)> test_fn = gcem::pow<long double, long double>;
    std::string test_fn_name = "gcem::pow";

    std::function<long double (long double, long double)> std_fn  = [] (long double x, long double y) -> long double { return std::pow(x,y); };
    std::string std_fn_name = "std::pow";

    //

    static constexpr long double test_vals_1[] = { 0.199900000000000208L, 0.5L, 1.5L, 41.5L };
    static constexpr long double test_vals_2[] = { 3.5L, 2.0L, 0.99L, 7.0L };

    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,0,test_fn,std_fn,true," ",5,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,1,test_fn_int,std_fn,true," ",3,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,2,test_fn,std_fn,true," ",3,18,false,false);
    PRINT_TEST_2_COMPARE(test_fn_name,std_fn_name,test_vals_1,test_vals_2,3,test_fn_int,std_fn,false," ",3,18,false,false);

    //

    std::cout << "\n*** end pow test ***\n" << std::endl;

    return 0;
}
