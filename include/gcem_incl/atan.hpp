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

/*
 * compile-time arctangent function
 */

// see
// http://functions.wolfram.com/ElementaryFunctions/ArcTan/10/0001/
// http://functions.wolfram.com/ElementaryFunctions/ArcTan/06/01/06/01/0002/

#ifndef _gcem_atan_HPP
#define _gcem_atan_HPP

// Series

// template<typename T>
// constexpr
// T
// atan_series_order(const T x, const int order)
// {
//     return ( order == 1 ? GCEM_HALF_PI - 1.0L/x :
//              order == 2 ? GCEM_HALF_PI - 1.0L/x + 1.0L/(3.0L * x*x*x) - 1/(5.0L * pow(x,5)) :
//              order == 3 ? GCEM_HALF_PI - 1.0L/x + 1.0L/(3.0L * x*x*x) - 1/(5.0L * pow(x,5)) + 1.0L/(7.0L * pow(x,7)) - 1/(9.0L * pow(x,9)) :
//              order == 4 ? GCEM_HALF_PI - 1.0L/x + 1.0L/(3.0L * x*x*x) - 1/(5.0L * pow(x,5)) + 1.0L/(7.0L * pow(x,7)) - 1/(9.0L * pow(x,9)) + 1.0L/(11.0L * pow(x,11)) - 1/(13.0L * pow(x,13)) :
//              order == 5 ? GCEM_HALF_PI - 1.0L/x + 1.0L/(3.0L * x*x*x) - 1/(5.0L * pow(x,5)) + 1.0L/(7.0L * pow(x,7)) - 1/(9.0L * pow(x,9)) + 1.0L/(11.0L * pow(x,11)) - 1/(13.0L * pow(x,13)) + 1.0L/(15.0L * pow(x,15)) - 1/(17.0L * pow(x,17)) :
//              order == 6 ? GCEM_HALF_PI - 1.0L/x + 1.0L/(3.0L * x*x*x) - 1/(5.0L * pow(x,5)) + 1.0L/(7.0L * pow(x,7)) - 1/(9.0L * pow(x,9)) + 1.0L/(11.0L * pow(x,11)) - 1/(13.0L * pow(x,13)) + 1.0L/(15.0L * pow(x,15)) - 1/(17.0L * pow(x,17)) + 1.0L/(19.0L * pow(x,19)) - 1/(21.0L * pow(x,21)) :
//                           GCEM_HALF_PI - 1.0L/x + 1.0L/(3.0L * x*x*x) - 1/(5.0L * pow(x,5)) + 1.0L/(7.0L * pow(x,7)) - 1/(9.0L * pow(x,9)) + 1.0L/(11.0L * pow(x,11)) - 1/(13.0L * pow(x,13)) + 1.0L/(15.0L * pow(x,15)) - 1/(17.0L * pow(x,17)) + 1.0L/(19.0L * pow(x,19)) - 1/(21.0L * pow(x,21)) + 1.0L/(23.0L * pow(x,23)) - 1/(25.0L * pow(x,25)) );
// }

template<typename T>
constexpr
T
atan_series_order(const T x, const T x_pow, const int order, const int max_order)
{
    return ( order == 1        ? GCEM_HALF_PI - 1.0L/x + atan_series_order(x*x,pow(x,3),order+1,max_order) : // NOTE: x changes to x*x for order > 1
             order < max_order ? T(1.0)/( T((order-1)*4 - 1) * x_pow ) - T(1.0)/( T((order-1)*4 + 1) * x_pow*x) + atan_series_order(x,x_pow*x*x,order+1,max_order) :
                                 T(1.0)/( T((order-1)*4 - 1) * x_pow ) - T(1.0)/( T((order-1)*4 + 1) * x_pow*x) );
}

template<typename T>
constexpr
T
atan_series_main(const T x)
{
    return ( x < T(3)    ? atan_series_order(x,x,1,10) :  // O(1/x^39)
             x < T(4)    ? atan_series_order(x,x,1,9) :   // O(1/x^35)
             x < T(5)    ? atan_series_order(x,x,1,8) :   // O(1/x^31)
             x < T(7)    ? atan_series_order(x,x,1,7) :   // O(1/x^27)
             x < T(11)   ? atan_series_order(x,x,1,6) :   // O(1/x^23)
             x < T(25)   ? atan_series_order(x,x,1,5) :   // O(1/x^19)
             x < T(100)  ? atan_series_order(x,x,1,4) :   // O(1/x^15)
             x < T(1000) ? atan_series_order(x,x,1,3) :   // O(1/x^11)
                           atan_series_order(x,x,1,2) );  // O(1/x^7)
}

// CF

template<typename T>
constexpr
T
atan_cf_recur(const T xx, const int depth, const int max_depth)
{
    return ( depth < max_depth ? (2*depth - 1) + depth*depth*xx/atan_cf_recur(xx,depth+1,max_depth) : T(2*depth - 1) );
}

template<typename T>
constexpr
T
atan_cf_main(const T x)
{
    return ( x < T(0.5) ? x/atan_cf_recur(x*x,1, 15 ) : 
             x < T(1.0) ? x/atan_cf_recur(x*x,1, 25 ) : 
             x < T(1.5) ? x/atan_cf_recur(x*x,1, 35 ) : 
             x < T(2.0) ? x/atan_cf_recur(x*x,1, 45 ) : 
                          x/atan_cf_recur(x*x,1, 52 ) );
            //  x < T(2.5) ? x/atan_cf_recur(x*x,1, 52 ) : 
            //  x < T(3.0) ? x/atan_cf_recur(x*x,1, 65 ) :
            //               x/atan_cf_recur(x*x,1, 72 ) );
}

//

template<typename T>
constexpr
T
atan_int(const T x)
{
    return ( x > T(2.5) ? atan_series_main(x) : atan_cf_main(x) );
}

template<typename T>
constexpr
T
atan(const T x)
{
    return ( GCLIM<T>::epsilon() > abs(x) ? T(0.0) :
             //
             x < T(0.0) ? -atan_int(-x) : atan_int(x) );
}

#endif
