/*################################################################################
  ##
  ##   Copyright (C) 2016-2018 Keith O'Hara
  ##
  ##   This file is part of the GCE-Math C++ library.
  ##
  ##   GCE-Math is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   GCE-Math is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

#include <limits>
#include <type_traits> // for is_integral

//
// constants

namespace gcem {
    template<class T>
    using GCEM_LIM = std::numeric_limits<T>;
}

#ifndef GCEM_LOG_2
    #define GCEM_LOG_2 0.693147180559945309417L
#endif

#ifndef GCEM_PI
    #define GCEM_PI 3.14159265358979323846L
#endif

#ifndef GCEM_LOG_PI
    #define GCEM_LOG_PI 1.14472988584940017414L
#endif

#ifndef GCEM_LOG_2PI
    #define GCEM_LOG_2PI 1.83787706640934548356L
#endif

#ifndef GCEM_LOG_SQRT_2PI
    #define GCEM_LOG_SQRT_2PI 0.918938533204672741780L
#endif

#ifndef GCEM_SQRT_2
    #define GCEM_SQRT_2 1.41421356237309504880L
#endif

#ifndef GCEM_HALF_PI
    #define GCEM_HALF_PI 1.57079632679489661923L
#endif

#ifndef GCEM_SQRT_PI
    #define GCEM_SQRT_PI 1.77245385090551602730L
#endif

#ifndef GCEM_SQRT_HALF_PI
    #define GCEM_SQRT_HALF_PI 1.25331413731550025121L
#endif

#ifndef GCEM_E
    #define GCEM_E 2.71828182845904523536L
#endif

//
// convergence settings

// #ifndef GCEM_ATAN_MAX_ITER
//     #define GCEM_ATAN_MAX_ITER 25
// #endif

#ifndef GCEM_ERF_MAX_ITER
    #define GCEM_ERF_MAX_ITER 35
#endif

#ifndef GCEM_ERF_INV_MAX_ITER
    #define GCEM_ERF_INV_MAX_ITER 45
#endif

#ifndef GCEM_EXP_MAX_ITER_SMALL
    #define GCEM_EXP_MAX_ITER_SMALL 25
#endif

// #ifndef GCEM_LOG_TOL
//     #define GCEM_LOG_TOL 1E-14
// #endif

#ifndef GCEM_LOG_MAX_ITER_SMALL
    #define GCEM_LOG_MAX_ITER_SMALL 25
#endif

#ifndef GCEM_LOG_MAX_ITER_BIG
    #define GCEM_LOG_MAX_ITER_BIG 255
#endif

#ifndef GCEM_INCML_BETA_TOL
    #define GCEM_INCML_BETA_TOL 1E-15
#endif

#ifndef GCEM_INCML_BETA_MAX_ITER
    #define GCEM_INCML_BETA_MAX_ITER 205
#endif

#ifndef GCEM_INCML_BETA_INV_MAX_ITER
    #define GCEM_INCML_BETA_INV_MAX_ITER 35
#endif

#ifndef GCEM_INCML_GAMMA_MAX_ITER
    #define GCEM_INCML_GAMMA_MAX_ITER 55
#endif

#ifndef GCEM_INCML_GAMMA_INV_MAX_ITER
    #define GCEM_INCML_GAMMA_INV_MAX_ITER 35
#endif

#ifndef GCEM_SQRT_TOL
    #define GCEM_SQRT_TOL 1E-15
#endif

#ifndef GCEM_TAN_MAX_ITER
    #define GCEM_TAN_MAX_ITER 35
#endif

#ifndef GCEM_TANH_MAX_ITER
    #define GCEM_TANH_MAX_ITER 35
#endif
