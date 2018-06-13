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
#include <functional>

//
// tolerance

#ifndef TEST_ERR_TOL
#define TEST_ERR_TOL 1e-14
#endif

//
// one input

template<typename T>
inline
T
print_test_1(const std::string fn_name, const T val_inp_1, std::function<T (const T val_inp)> fn_eval, 
             const bool new_line=false, const std::string extra_space="", 
             const int precision_1=2, const int precision_2=18)
{
    T f_val = fn_eval(val_inp_1);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(precision_1) << fn_name \
              << "(" << val_inp_1 << ")" << extra_space << " = " \
              << std::setprecision(precision_2) << f_val << std::endl;
    if (new_line) std::cout << std::endl;
    return f_val;
}

#define PRINT_TEST_1_EXPECT(fn_name, vals_inp, j, fn_eval, expected_val,                                        \
                            new_line, extra_space,                                                              \
                            precision_1, precision_2, is_inf, is_nan)                                           \
{                                                                                                               \
    constexpr long double val_1 = vals_inp[j];                                                                  \
                                                                                                                \
    long double f_val = print_test_1(fn_name,val_1,fn_eval,false,extra_space,precision_1,precision_2);          \
                                                                                                                \
    bool test_pass = false;                                                                                     \
                                                                                                                \
    printf("  -");                                                                                              \
    if (!is_nan && !is_inf) {                                                                                   \
        long double err_val = std::abs(f_val - expected_val);                                                   \
        printf(" error value = %LE.", err_val);                                                                 \
        test_pass = (err_val < TEST_ERR_TOL) ? true : false;                                                    \
    } else if (is_nan) {                                                                                        \
        if (std::isnan(f_val)) {                                                                                \
            test_pass = true;                                                                                   \
        }                                                                                                       \
    } else if (is_inf) {                                                                                        \
        if (std::isinf(f_val)) {                                                                                \
            test_pass = true;                                                                                   \
        }                                                                                                       \
    } else {                                                                                                    \
        printf("unknown error!");                                                                               \
    }                                                                                                           \
                                                                                                                \
    if (test_pass) {                                                                                            \
        std::cout << "\033[32m OK.\033[0m" << std::endl;                                                        \
    } else {                                                                                                    \
        std::cout << "\033[31m FAIL.\033[0m" << std::endl;                                                      \
    }                                                                                                           \
                                                                                                                \
    if (new_line) std::cout << std::endl;                                                                       \
}                                                                                                               \
                                                                                                             \

#define PRINT_TEST_1_COMPARE(fn_name_1, fn_name_2, vals_inp, j,                                                 \
                             fn_eval_1, fn_eval_2, new_line, extra_space,                                       \
                             precision_1, precision_2, is_inf, is_nan)                                          \
{                                                                                                               \
    constexpr long double c_val = vals_inp[j];                                                                  \
    long double x_val = vals_inp[j];                                                                            \
                                                                                                                \
    long double f_val_1 = print_test_1(fn_name_1,c_val,fn_eval_1,false,"",precision_1,precision_2);             \
    long double f_val_2 = print_test_1(fn_name_2,x_val,fn_eval_2,false,extra_space,precision_1,precision_2);    \
                                                                                                                \
    bool test_pass = false;                                                                                     \
                                                                                                                \
    printf("  -");                                                                                              \
    if (!is_nan && !is_inf) {                                                                                   \
        long double err_val = std::abs(f_val_1 - f_val_2);                                                      \
        printf(" error value = %LE.", err_val);                                                                 \
        test_pass = (err_val < TEST_ERR_TOL) ? true : false;                                                    \
    } else if (is_nan) {                                                                                        \
        if (std::isnan(f_val_1) && std::isnan(f_val_2)) {                                                       \
            test_pass = true;                                                                                   \
        }                                                                                                       \
    } else if (is_inf) {                                                                                        \
        if (std::isinf(f_val_1) && std::isinf(f_val_2)) {                                                       \
            test_pass = true;                                                                                   \
        }                                                                                                       \
    } else {                                                                                                    \
        printf("unknown error!");                                                                               \
    }                                                                                                           \
                                                                                                                \
    if (test_pass) {                                                                                            \
        std::cout << "\033[32m OK.\033[0m" << std::endl;                                                        \
    } else {                                                                                                    \
        std::cout << "\033[31m FAIL.\033[0m" << std::endl;                                                      \
    }                                                                                                           \
                                                                                                                \
    if (new_line) std::cout << std::endl;                                                                       \
}                                                                                                               \

//
// two inputs

template<typename T>
inline
T
print_test_2(const std::string fn_name, const T val_inp_1, const T val_inp_2, std::function<T (const T val_inp, const T par_inp)> fn_eval, 
             const bool new_line=false, const std::string extra_space="", 
             const int precision_1=2, const int precision_2=18)
{
    T f_val = fn_eval(val_inp_1,val_inp_2);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(precision_1) << fn_name \
              << "(" << val_inp_1 << "," << val_inp_2 << ")" << extra_space << " = " \
              << std::setprecision(precision_2) << f_val << std::endl;
    if (new_line) std::cout << std::endl;
    return f_val;
}

#define PRINT_TEST_2_EXPECT(fn_name, vals_inp_1, vals_inp_2, j, fn_eval, expected_val,                          \
                            new_line, extra_space,                                                              \
                            precision_1, precision_2, is_inf, is_nan)                                           \
{                                                                                                               \
    constexpr long double val_1 = vals_inp_1[j];                                                                \
    constexpr long double val_2 = vals_inp_2[j];                                                                \
                                                                                                                \
    long double f_val = print_test_2(fn_name,val_1,val_2,fn_eval,false,extra_space,precision_1,precision_2);    \
                                                                                                                \
    bool test_pass = false;                                                                                     \
                                                                                                                \
    printf("  -");                                                                                              \
    if (!is_nan && !is_inf) {                                                                                   \
        long double err_val = std::abs(f_val - expected_val);                                                   \
        printf(" error value = %LE.", err_val);                                                                 \
        test_pass = (err_val < TEST_ERR_TOL) ? true : false;                                                    \
    } else if (is_nan) {                                                                                        \
        if (std::isnan(f_val)) {                                                                                \
            test_pass = true;                                                                                   \
        }                                                                                                       \
    } else if (is_inf) {                                                                                        \
        if (std::isinf(f_val)) {                                                                                \
            test_pass = true;                                                                                   \
        }                                                                                                       \
    } else {                                                                                                    \
        printf("unknown error!");                                                                               \
    }                                                                                                           \
                                                                                                                \
    if (test_pass) {                                                                                            \
        std::cout << "\033[32m OK.\033[0m" << std::endl;                                                        \
    } else {                                                                                                    \
        std::cout << "\033[31m FAIL.\033[0m" << std::endl;                                                      \
    }                                                                                                           \
                                                                                                                \
    if (new_line) std::cout << std::endl;                                                                       \
}                                                                                                               \

#define PRINT_TEST_2_COMPARE(fn_name_1, fn_name_2, vals_inp_1, vals_inp_2, j,                                           \
                             fn_eval_1, fn_eval_2, new_line, extra_space,                                               \
                             precision_1, precision_2, is_inf, is_nan)                                                  \
{                                                                                                                       \
    constexpr long double c_val_1 = vals_inp_1[j];                                                                      \
    constexpr long double c_val_2 = vals_inp_2[j];                                                                      \
    long double x_val_1 = vals_inp_1[j];                                                                                \
    long double x_val_2 = vals_inp_2[j];                                                                                \
                                                                                                                        \
    long double f_val_1 = print_test_2(fn_name_1,c_val_1,c_val_2,fn_eval_1,false,"",precision_1,precision_2);           \
    long double f_val_2 = print_test_2(fn_name_2,x_val_1,x_val_2,fn_eval_2,false,extra_space,precision_1,precision_2);  \
                                                                                                                        \
    bool test_pass = false;                                                                                             \
                                                                                                                        \
    printf("  -");                                                                                                      \
    if (!is_nan && !is_inf) {                                                                                           \
        long double err_val = std::abs(f_val_1 - f_val_2);                                                              \
        printf(" error value = %LE.", err_val);                                                                         \
        test_pass = (err_val < TEST_ERR_TOL) ? true : false;                                                            \
    } else if (is_nan) {                                                                                                \
        if (std::isnan(f_val_1) && std::isnan(f_val_2)) {                                                               \
            test_pass = true;                                                                                           \
        }                                                                                                               \
    } else if (is_inf) {                                                                                                \
        if (std::isinf(f_val_1) && std::isinf(f_val_2)) {                                                               \
            test_pass = true;                                                                                           \
        }                                                                                                               \
    } else {                                                                                                            \
        printf("unknown error!");                                                                                       \
    }                                                                                                                   \
                                                                                                                        \
    if (test_pass) {                                                                                                    \
        std::cout << "\033[32m OK.\033[0m" << std::endl;                                                                \
    } else {                                                                                                            \
        std::cout << "\033[31m FAIL.\033[0m" << std::endl;                                                              \
    }                                                                                                                   \
                                                                                                                        \
    if (new_line) std::cout << std::endl;                                                                               \
}                                                                                                                       \

//
// three inputs

template<typename T>
inline
T
print_test_3(const std::string fn_name, const T val_inp_1, const T val_inp_2, const T val_inp_3, 
             std::function<T (const T val_inp, const T par_inp_1, const T par_inp_2)> fn_eval, 
             const bool new_line=false, const std::string extra_space="", 
             const int precision_1=2, const int precision_2=18)
{
    T f_val = fn_eval(val_inp_1,val_inp_2,val_inp_3);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(precision_1) << fn_name \
              << "(" << val_inp_1 << "," << val_inp_2 << "," << val_inp_3 << ")" << extra_space << " = " \
              << std::setprecision(precision_2) << f_val << std::endl;
    if (new_line) std::cout << std::endl;
    return f_val;
}

#define PRINT_TEST_3_EXPECT(fn_name, vals_inp_1, vals_inp_2, vals_inp_3,                                            \
                            j, fn_eval, expected_val,                                                               \
                            new_line, extra_space,                                                                  \
                            precision_1, precision_2, is_inf, is_nan)                                               \
{                                                                                                                   \
    constexpr long double val_1 = vals_inp_1[j];                                                                    \
    constexpr long double val_2 = vals_inp_2[j];                                                                    \
    constexpr long double val_3 = vals_inp_3[j];                                                                    \
                                                                                                                    \
    long double f_val = print_test_3(fn_name,val_1,val_2,val_3,fn_eval,false,extra_space,precision_1,precision_2);  \
                                                                                                                    \
    bool test_pass = false;                                                                                         \
                                                                                                                    \
    printf("  -");                                                                                                  \
    if (!is_nan && !is_inf) {                                                                                       \
        long double err_val = std::abs(f_val - expected_val);                                                       \
        printf(" error value = %LE.", err_val);                                                                     \
        test_pass = (err_val < TEST_ERR_TOL) ? true : false;                                                        \
    } else if (is_nan) {                                                                                            \
        if (std::isnan(f_val)) {                                                                                    \
            test_pass = true;                                                                                       \
        }                                                                                                           \
    } else if (is_inf) {                                                                                            \
        if (std::isinf(f_val)) {                                                                                    \
            test_pass = true;                                                                                       \
        }                                                                                                           \
    } else {                                                                                                        \
        printf("unknown error!");                                                                                   \
    }                                                                                                               \
                                                                                                                    \
    if (test_pass) {                                                                                                \
        std::cout << "\033[32m OK.\033[0m" << std::endl;                                                            \
    } else {                                                                                                        \
        std::cout << "\033[31m FAIL.\033[0m" << std::endl;                                                          \
    }                                                                                                               \
                                                                                                                    \
    if (new_line) std::cout << std::endl;                                                                           \
}                                                                                                                   \
