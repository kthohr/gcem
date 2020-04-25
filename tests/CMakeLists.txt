################################################################################
##
##   Copyright (C) 2016-2020 Keith O'Hara
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
################################################################################

cmake_minimum_required(VERSION 3.1)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    project(gcem-test)

    find_package(gcem REQUIRED CONFIG)
    set(GCEM_INCLUDE_DIR ${gcem_INCLUDE_DIRS})
endif ()

message(STATUS "Forcing tests build type to Release")
set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)

include(CheckCXXCompilerFlag)

#

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Intel")
    CHECK_CXX_COMPILER_FLAG("-std=c++11" HAS_CPP11_FLAG)
    if (HAS_CPP11_FLAG)
        if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -O0 -Wall -Wextra --coverage -fno-inline -fno-inline-small-functions -fno-default-inline")
        else()
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -O0 -Wall -Wextra --coverage -fno-inline")
        endif()
    else()
        message(FATAL_ERROR "Unsupported compiler -- gcem requires C++11 support!")
    endif()
endif()

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /MP /bigobj")
    set(CMAKE_EXE_LINKER_FLAGS /MANIFEST:NO)
endif()

#

set(GCEM_TESTS
    acos.cpp
    acosh.cpp
    asin.cpp
    asinh.cpp
    atan.cpp
    atan2.cpp
    atanh.cpp
    binomial_coef.cpp
    cos.cpp
    cosh.cpp
    erf.cpp
    erf_inv.cpp
    exp.cpp
    expm1.cpp
    factorial.cpp
    fmod.cpp
    gcd.cpp
    incomplete_beta.cpp
    incomplete_beta_inv.cpp
    incomplete_gamma.cpp
    incomplete_gamma_inv.cpp
    is_odd.cpp
    lcm.cpp
    lgamma.cpp
    log.cpp
    log1p.cpp
    log2.cpp
    log_binomial_coef.cpp
    other.cpp
    pow.cpp
    rounding.cpp
    sin.cpp
    sinh.cpp
    sqrt.cpp
    tan.cpp
    tanh.cpp
    tgamma.cpp
)

#

set(GCEM_TESTS_EX "")

foreach( file_ ${GCEM_TESTS} )
    string( REPLACE ".cpp" ".test" testname ${file_} )

    add_executable( ${testname} EXCLUDE_FROM_ALL ${file_} ${GCEM_HEADERS})
    target_link_libraries( ${testname} gcem )
    
    list(APPEND GCEM_TESTS_EX ${testname})
endforeach()

add_custom_target(gcem_tests DEPENDS ${GCEM_TESTS_EX})

#
