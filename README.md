# GCE-Math &nbsp; [![Build Status](https://travis-ci.org/kthohr/gcem.svg?branch=master)](https://travis-ci.org/kthohr/gcem) [![Coverage Status](https://codecov.io/github/kthohr/gcem/coverage.svg?branch=master)](https://codecov.io/github/kthohr/gcem?branch=master)

## About

GCE-Math (**G**eneralized **C**onstant **E**xpression Math) is a templated C++ library for compile-time computation of mathematical functions.

* GCE-Math makes extensive use of ```constexpr``` functions and recursive templates to evaluate continued fraction and series-type expansions of special mathematical functions.
* The library is written in concise C++11 ```constexpr``` format, and is C++11/14/17 compatible.
* The ```gcem::``` syntax is identical to the C++ standard library.
* Tested and accurate to machine precision against the C++ standard library.

## Status

The library is actively maintained, and is still being extended.

A list of features includes:

* basic standard library functions, such as:
    - ```abs```, ```exp```, ```log```, ```max```, ```min```, ```pow```, ```sqrt```
* trigonometric functions:
    - basic: ```cos```, ```sin```, ```tan```
    - inverse: ```acos```, ```asin```, ```atan```
    - hyperbolic (area) functions: ```cosh```, ```sinh```, ```tanh```, ```acosh```, ```asinh```, ```atanh```
* special functions:
    - beta and gamma functions: ```beta```, ```lbeta```, ```lgamma```, ```tgamma```
    - the Gaussian error function and inverse error function: ```erf```, ```erf_inv```
    - (regularized) incomplete beta and incomplete gamma functions: ```incomplete_beta```, ```incomplete_gamma```
    - inverse incomplete beta and incomplete gamma functions: ```incomplete_beta_inv```, ```incomplete_gamma_inv```

GCE-Math functions are written in a generic template format. For example, the [Gaussian error function](https://en.wikipedia.org/wiki/Error_function) is written as:
```cpp
template<typename T>
constexpr
T
erf(const T x)
```
For users unfamiliar with template programming, note that the output type ('T') is determined based on the input type: ```float```, ```double```, ```long double```, etc. So take care when passing integral-type inputs.


## Installation

GCE-Math is a header-only library and does not require any additional libraries (beyond a C++11 compatible compiler). 

Simply include the gcem header files with your project.

## Example

Compute the log Gamma function at a point:

```cpp
#include "gcem.hpp"

int main()
{
    constexpr long double x = 1.5;
    constexpr long double res = gcem::lgamma(x);

    return 0;
}
```

To build the full test suite:

```bash
# clone gcem from GitHub
git clone -b master --single-branch https://github.com/kthohr/gcem ./gcem
# compile tests
cd ./gcem/tests
make
./run_tests
```

## Related libraries

For a library built on the GCEM compile-time functionality, see [StatsLib](https://github.com/kthohr/stats).

## Author

Keith O'Hara

## License

GPL (>= 2)
