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
project(gcem)

set(GCEM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

#

file(STRINGS "${GCEM_INCLUDE_DIR}/gcem_incl/gcem_options.hpp" gcem_version_defines
     REGEX "#define GCEM_VERSION_(MAJOR|MINOR|PATCH)")

foreach(ver ${gcem_version_defines})
    if(ver MATCHES "#define GCEM_VERSION_(MAJOR|MINOR|PATCH) +([^ ]+)$")
        set(GCEM_VERSION_${CMAKE_MATCH_1} "${CMAKE_MATCH_2}" CACHE INTERNAL "")
    endif()
endforeach()

set(${PROJECT_NAME}_VERSION
    ${GCEM_VERSION_MAJOR}.${GCEM_VERSION_MINOR}.${GCEM_VERSION_PATCH})
message(STATUS "GCE-Math version ${${PROJECT_NAME}_VERSION}")

#

set(GCEM_HEADERS
    ${GCEM_INCLUDE_DIR}/gcem.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/abs.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/acos.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/acosh.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/asin.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/asinh.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/atan.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/atan2.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/atanh.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/beta.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/binomial_coef.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/ceil.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/cos.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/cosh.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/erf_inv.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/erf.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/exp.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/expm1.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/factorial.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/find_exponent.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/find_fraction.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/find_whole.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/floor.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/fmod.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/gcd.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/gcem_options.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/incomplete_beta.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/incomplete_beta_inv.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/incomplete_gamma.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/incomplete_gamma_inv.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/is_even.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/is_odd.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/is_inf.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/is_nan.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/is_finite.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/lbeta.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/lcm.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/lgamma.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/lmgamma.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/log_binomial_coef.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/log.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/log1p.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/log2.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/mantissa.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/max.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/min.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/neg_zero.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/pow_integral.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/pow.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/quadrature/gauss_legendre_30.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/quadrature/gauss_legendre_50.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/round.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/sgn.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/sin.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/sinh.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/sqrt.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/tan.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/tanh.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/tgamma.hpp
    ${GCEM_INCLUDE_DIR}/gcem_incl/trunc.hpp
)

#

add_library(gcem INTERFACE)
target_include_directories(gcem INTERFACE $<BUILD_INTERFACE:${GCEM_INCLUDE_DIR}>
                                          $<INSTALL_INTERFACE:include>)

OPTION(GCEM_BUILD_TESTS "gcem test suite" OFF)

if(GCEM_BUILD_TESTS)
    add_subdirectory(tests)
endif()

#

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGETS gcem
        EXPORT ${PROJECT_NAME}-targets)

#

export(EXPORT ${PROJECT_NAME}-targets
       FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake")

install(DIRECTORY ${GCEM_INCLUDE_DIR}/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#

set(GCEM_CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}" CACHE STRING "install path for gcemConfig.cmake")

configure_package_config_file(cmake_files/${PROJECT_NAME}Config.cmake.in
                              "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
                              INSTALL_DESTINATION ${GCEM_CMAKECONFIG_INSTALL_DIR})

#

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
                                 VERSION ${${PROJECT_NAME}_VERSION}
                                 COMPATIBILITY SameMajorVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION ${GCEM_CMAKECONFIG_INSTALL_DIR})

install(EXPORT ${PROJECT_NAME}-targets
        FILE ${PROJECT_NAME}Targets.cmake
        DESTINATION ${GCEM_CMAKECONFIG_INSTALL_DIR})
