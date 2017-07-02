/*################################################################################
  ##
  ##   Copyright (C) 2016-2017 Keith O'Hara
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

/* 
 * inverse of the incomplete gamma function
 *
 * Keith O'Hara
 * 06/15/2016
 *
 * This version:
 * 07/01/2017
 */

#ifndef _gcem_incomplete_gamma_inv_HPP
#define _gcem_incomplete_gamma_inv_HPP

inline
bool
incomplete_gamma_inv(double a, double p, double& ret)
{
    //
    bool success = false;
    const int iter_max = 1000;
    const double err_tol = 1E-08;

    double value = 0.0;
    const double g = lgamma(a);

    if (a > 1.0) {
        //
        // use 26.2.23 in Abramowitz and Stegun (1972 print)
        const double p_term = (p > 0.5) ? log(1.0 - p) : log(p);
        const double t_val = sqrt(-2.0*p_term);

        const double c_0 = 2.515517, c_1 = 0.802853, c_2 = 0.010328;
        const double d_0 = 1.0, d_1 = 1.432788, d_2 = 0.189269, d_3 = 0.001308;

        value = t_val - (c_0 + c_1*t_val + c_2*t_val*t_val)/(d_0 + d_1*t_val + d_2*t_val*t_val + d_3*t_val*t_val*t_val);

        if (p > 0.5) {
            value *= -1.0;
        }

        const double pow_term = pow_dbl(1.0 - 1.0/(9.0*a) - value/(3.0*sqrt(a)),3); // 26.4.17 in Abramowitz and Stegun (1972 print)
        value = max(1E-04, a*pow_term);
    } else {
        const double t_val = 1.0 - 0.253*a - 0.12*a*a;

        if (p < t_val) {
            value = pow_dbl(p/t_val,1.0/a);
        } else {
            value = 1.0 - log(1.0 - (p - t_val)/(1.0 - t_val));
        }
    }

    if (value <= 0.0) {
        printf("error: incomplete_gamma_inv value <= 0 found.\n");
        ret = 0.0;
        return false;
    }
    //
    int iter = 0;
    double err_val, deriv_1, deriv_2, ratio_val_1, ratio_val_2, halley_direc=1.0, ig_val=1.0;

    while (abs(halley_direc) >= err_tol && iter < iter_max) {
        iter++;
        //
        // incomplete_gamma(a,value,ig_val);
        ig_val = incomplete_gamma(a,value);
        err_val = ig_val - p; // err_val = f(x)
        
        deriv_1 = exp( - value + (a - 1.0)*log(value) - g ); // derivative of the incomplete gamma function w.r.t. x
        deriv_2 = deriv_1*((a - 1.0)/value - 1.0);                     // second derivative of the incomplete gamma function w.r.t. x

        ratio_val_1 = err_val / deriv_1;
        ratio_val_2 = deriv_2 / deriv_1;

        halley_direc = ratio_val_1 / max( 0.8, min( 1.2, 1.0 - 0.5*ratio_val_1*ratio_val_2 ) );
        value -= halley_direc;
        //
        if (value <= 0.0) {
            value = 0.5*(value + halley_direc);
        }
    }
    //
    if (abs(halley_direc) < err_tol && iter < iter_max) {
        ret = value;
        success = true;
    } else {
        printf("error: incomplete_gamma_inv failed to converge.\n");
    }
    //
    return success;
}

#endif
