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
 * compile-time log-gamma function; see:
 * http://my.fit.edu/~gabdo/gamma.txt
 *
 * Keith O'Hara
 * 06/25/2017
 *
 * This version:
 * 07/09/2017
 */

#ifndef _gcem_lgamma_HPP
#define _gcem_lgamma_HPP

// P. Godfrey's coefficients:
//
//  0.99999999999999709182
//  57.156235665862923517
// -59.597960355475491248
//  14.136097974741747174
//  -0.49191381609762019978
//    .33994649984811888699e-4
//    .46523628927048575665e-4
//   -.98374475304879564677e-4
//    .15808870322491248884e-3
//   -.21026444172410488319e-3
//    .21743961811521264320e-3
//   -.16431810653676389022e-3
//    .84418223983852743293e-4
//   -.26190838401581408670e-4
//    .36899182659531622704e-5

constexpr
long double
lgamma_coef_term(const long double x)
{
    return (  0.99999999999999709182L             + 57.156235665862923517L / (x+1)       - 59.597960355475491248L / (x+2)       + 14.136097974741747174L / (x+3)       + \
             -0.49191381609762019978L / (x+4)     +   .33994649984811888699e-4L / (x+5)  +   .46523628927048575665e-4L / (x+6)  -   .98374475304879564677e-4L / (x+7)  + \
               .15808870322491248884e-3L / (x+8)  -   .21026444172410488319e-3L / (x+9)  +   .21743961811521264320e-3L / (x+10) -   .16431810653676389022e-3L / (x+11) + \
               .84418223983852743293e-4L / (x+12) -   .26190838401581408670e-4L / (x+13) +   .36899182659531622704e-5L / (x+14) );
}

constexpr
long double
lgamma_term_2(const long double x)
{ //
    return ( GCEM_LOG_SQRT_2PI + log(lgamma_coef_term(x)) );
}

constexpr
long double
lgamma_term_1(const long double x)
{ // 607/128 + 0.5 = 5.2421875
    return ( (x + 0.5)*log(x+5.2421875L) - (x + 5.2421875L) );
}

constexpr
long double
lgamma_int(const long double x)
{ // returns lngamma(x+1)
    return ( lgamma_term_1(x) + lgamma_term_2(x) );
}

constexpr
long double
lgamma(const long double x)
{
    return ( x == 1 ? 0 : lgamma_int(x-1) );
}

#endif
