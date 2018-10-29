# GCE-Math
[![Build Status](https://travis-ci.org/kthohr/gcem.svg?branch=master)](https://travis-ci.org/kthohr/gcem) [![Build status](https://ci.appveyor.com/api/projects/status/5kxxkmisln1j4h6b?svg=true)](https://ci.appveyor.com/project/kthohr/gcem) [![Coverage Status](https://codecov.io/github/kthohr/gcem/coverage.svg?branch=master)](https://codecov.io/github/kthohr/gcem?branch=master) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/19bf49e64ca04c848f6a0a8030d1f131)](https://www.codacy.com/app/kthohr/gcem?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=kthohr/gcem&amp;utm_campaign=Badge_Grade) [![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/kthohr/gcem.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/kthohr/gcem) [![Documentation Status](https://readthedocs.org/projects/gcem/badge/?version=latest)](https://gcem.readthedocs.io/en/latest/?badge=latest)

GCE-Math (**G**eneralized **C**onstant **E**xpression Math) is a templated C++ library enabling compile-time computation of mathematical functions.

Features:

* The library is written in C++11 ```constexpr``` format, and is C++11/14/17 compatible.
* Continued fraction and series expansions are implemented using recursive templates.
* The ```gcem::``` syntax is identical to the C++ standard library (`std::`).
* Tested and accurate to floating-point precision against the C++ standard library.
* Released under a permissive, non-GPL license.

**Author**: Keith O'Hara

[![License](https://img.shields.io/badge/Licence-Apache%202.0-blue.svg)](./LICENSE)

### Contents:
* [Status and Documentation](#status-and-documentation) 
* [Installation and Tests](#installation-and-tests)
* [Jupyter Notebook](#jupyter-notebook)
* [General Syntax](#general-syntax)
* [Examples](#examples)

## Status and Documentation

The library is actively maintained, and is still being extended. A list of features includes:

* basic library functions:
    - ```abs```, ```exp```, ```log```, ```max```, ```min```, ```pow```, ```sqrt```, ```gcd```, ```lcm```, and more
* trigonometric functions:
    - basic: ```cos```, ```sin```, ```tan```
    - inverse: ```acos```, ```asin```, ```atan```
* hyperbolic (area) functions: 
    - ```cosh```, ```sinh```, ```tanh```, ```acosh```, ```asinh```, ```atanh```
* special functions:
    - factorials and the binomial coefficient: ```factorial```, ```binomial_coef```
    - beta, gamma, and multivariate gamma functions: ```beta```, ```lbeta```, ```lgamma```, ```tgamma```, ```lmgamma```
    - the Gaussian error function and inverse error function: ```erf```, ```erf_inv```
    - (regularized) incomplete beta and incomplete gamma functions: ```incomplete_beta```, ```incomplete_gamma```
    - inverse incomplete beta and incomplete gamma functions: ```incomplete_beta_inv```, ```incomplete_gamma_inv```

Full documentation is available online:

[![Documentation Status](https://readthedocs.org/projects/gcem/badge/?version=latest)](https://gcem.readthedocs.io/en/latest/?badge=latest)

## Installation and Tests

GCE-Math is a header-only library and does not require any additional libraries (beyond a C++11 compatible compiler). Simply add the header files to your project using:
```cpp
#include "gcem.hpp"
```

### Conda

<!-- [![Anaconda-Server Badge](https://anaconda.org/kthohr/gcem/badges/platforms.svg)](https://anaconda.org/kthohr/gcem) -->

You can install GCE-Math using the conda package manager.

```bash
conda install gcem -c kthohr
```

### CMake

You can also install the library from source using CMake.

```bash
# clone gcem from GitHub
git clone https://github.com/kthohr/gcem ./gcem

# make a build directory
cd ./gcem
mkdir build
cd build

# generate Makefiles and install
cmake .. -DCMAKE_INSTALL_PREFIX=/gcem/install/location
make install
```
For example, `/gcem/install/location` could be `/usr/local/`.

### Test Suite

There are two ways to build the test suite. On Unix-alike systems, a Makefile is available under `tests/`.

```bash
cd ./gcem/tests
make
./run_tests
```

With CMake, the option `BUILD_TESTS=1` generates the necessary Makefiles to build the test suite.
```bash
cd ./gcem
mkdir build

cd build
cmake ../ -DBUILD_TESTS=1 -DCMAKE_INSTALL_PREFIX=/gcem/install/location
make gcem_tests

cd tests
./exp.test
```

## Jupyter Notebook

You can test the library online using an interactive Jupyter notebook: 

[![Binder](https://mybinder.org/badge.svg)](https://mybinder.org/v2/gh/kthohr/gcem/master?filepath=notebooks%2Fgcem.ipynb)

## General Syntax

GCE-Math functions are written as C++ templates with `constexpr` specifiers, the format of which might be confusing to users unfamiliar with template-based programming. As an example, the [Gaussian error function](https://en.wikipedia.org/wiki/Error_function) (```erf```) is defined as:
```cpp
template<typename T>
constexpr
return_t<T>
erf(const T x);
```
where a set of internal templated ```constexpr``` functions will implement a continued fraction expansion to return a value of type ```return_t<T>```. This output type ('```return_t<T>```') is generally determined by the input type, e.g., ```int```, ```float```, ```double```, ```long double```, etc. When ```T``` is an intergral type, the output will be upgraded to ```return_t<T> = double```, otherwise ```return_t<T> = T```. For types not covered by ```std::is_integral```, recasts should be used.

## Examples

To calculate 10!:

```cpp
#include "gcem.hpp"

int main()
{
    constexpr int x = 10;
    constexpr int res = gcem::factorial(x);

    return 0;
}
```
Inspecting the assembly code generated by Clang:
```assembly
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	push	rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Lcfi2:
	.cfi_def_cfa_register rbp
	xor	eax, eax
	mov	dword ptr [rbp - 4], 0
	mov	dword ptr [rbp - 8], 10
	mov	dword ptr [rbp - 12], 3628800
	pop	rbp
	ret
	.cfi_endproc
```
We see that a function call has been replaced by a numeric value (10! = 3628800).

Similarly, to compute the log Gamma function at a point:

```cpp
#include "gcem.hpp"

int main()
{
    constexpr long double x = 1.5;
    constexpr long double res = gcem::lgamma(x);

    return 0;
}
```
Assembly code:
```assembly
LCPI0_0:
	.long	1069547520              ## float 1.5
	.section	__TEXT,__literal16,16byte_literals
	.p2align	4
LCPI0_1:
	.quad	-622431863250851168     ## x86_fp80 -0.120782237635245167208
	.short	49147
	.space	6
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	push	rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Lcfi2:
	.cfi_def_cfa_register rbp
	xor	eax, eax
	mov	dword ptr [rbp - 4], 0
	fld	dword ptr [rip + LCPI0_0]
	fstp	xword ptr [rbp - 32]
	fld	xword ptr [rip + LCPI0_1]
	fstp	xword ptr [rbp - 48]
	pop	rbp
	ret
	.cfi_endproc
```

## Related libraries

For a library built on the GCEM compile-time functionality, see [StatsLib](https://github.com/kthohr/stats).

