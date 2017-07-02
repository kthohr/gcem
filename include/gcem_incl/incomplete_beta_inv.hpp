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
 * inverse of the incomplete beta function
 *
 * Keith O'Hara
 * 06/15/2016
 *
 * This version:
 * 06/23/2017
 */

#ifndef _gcem_incomplete_beta_inv_HPP
#define _gcem_incomplete_beta_inv_HPP

inline
bool
incomplete_beta_inv(double alpha_par, double beta_par, double p, double& ret)
{
    //
    bool success = false;
    const int iter_max = 1000;
    const double err_tol = 1E-08;

    if (alpha_par == 1.0 && beta_par == 1.0) {
        ret = p;
        return true;
    }

    double value;
    // const double lbeta = std::lgamma(alpha_par) + std::lgamma(beta_par) - std::lgamma(alpha_par + beta_par); // log beta function value
    const double lbeta = lgamma(alpha_par) + lgamma(beta_par) - lgamma(alpha_par + beta_par); // log beta function value
    //
    if (alpha_par > 1.0 && beta_par > 1.0) {
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

        // use 26.5.22 in Abramowitz and Stegun (1972 print)
        const double ab_term_1 = ( 1.0/(2*alpha_par - 1.0) + 1.0/(2*beta_par - 1.0) );
        const double ab_term_2 = ( 1.0/(2*beta_par - 1.0) - 1.0/(2*alpha_par - 1.0) );

        const double lambda = (value*value - 3.0)/6.0;
        const double h_term = 2.0 / ab_term_1;
        const double w_term = value * sqrt(h_term + lambda)/h_term - ab_term_2*(lambda + 5.0/6.0 -2.0/(3.0*h_term));
        
        value = alpha_par / (alpha_par + beta_par*exp(2.0*w_term));
    } else {
        const double term_1 = pow_dbl(alpha_par/(alpha_par+beta_par),alpha_par) / alpha_par;
        const double term_2 = pow_dbl(beta_par/(alpha_par+beta_par),beta_par) / beta_par;
        const double s_val = term_1 + term_2;

        const double check_val = term_1 / s_val;

        if (p <= check_val) {
            value = pow_dbl(p*s_val*alpha_par,1.0/alpha_par);
        } else {
            value = 1.0 - pow_dbl(p*s_val*beta_par,1.0/beta_par);
        }
    }

    if (value <= 0.0) {
        printf("error: incomplete_beta_inv value <= 0 found.\n");
        ret = 0.0;
        return false;
    }
    //
    int iter = 0;
    double err_val, deriv_1, deriv_2, ratio_val_1, ratio_val_2, halley_direc=1.0, ib_val=1.0;

    while (abs(halley_direc) >= err_tol && iter < iter_max) {
        iter++;
        //
        // incomplete_beta(alpha_par,beta_par,value,ib_val);
        ib_val = incomplete_beta(alpha_par,beta_par,value);
        err_val = ib_val - p; // err_val = f(x)
        
        deriv_1 = exp( (alpha_par-1.0)*log(value) + (beta_par-1.0)*log(1.0 - value) - lbeta ); // derivative of the incomplete gamma function w.r.t. x
        deriv_2 = deriv_1*((alpha_par - 1.0)/value - (beta_par - 1.0)/(1.0 - value));                         // second derivative of the incomplete gamma function w.r.t. x

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
        printf("error: incomplete_beta_inv failed to converge.\n");
    }
    //
    return success;
}

#endif
