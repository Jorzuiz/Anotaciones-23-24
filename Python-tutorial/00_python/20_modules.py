import math

print("It's math! It has type {}".format(type(math)))
## It's math! It has type <class 'module'>

print(dir(math))
## ['__doc__', '__loader__', '__name__', '__package__', '__spec__', 'acos', 'acosh', 'asin', 'asinh', 'atan', 'atan2',
##  'atanh', 'ceil', 'comb', 'copysign', 'cos', 'cosh', 'degrees', 'dist', 'e', 'erf', 'erfc', 'exp', 'expm1', 'fabs',
##  'factorial', 'floor', 'fmod', 'frexp', 'fsum', 'gamma', 'gcd', 'hypot', 'inf', 'isclose', 'isfinite', 'isinf',
##  'isnan', 'isqrt', 'lcm', 'ldexp', 'lgamma', 'log', 'log10', 'log1p', 'log2', 'modf', 'nan', 'nextafter', 'perm',
##  'pi', 'pow', 'prod', 'radians', 'remainder', 'sin', 'sinh', 'sqrt', 'tan', 'tanh', 'tau', 'trunc', 'ulp']

print("pi to 4 significant digits = {:.4}".format(math.pi))
## pi to 4 significant digits = 3.142

print(math.log(32, 2))
## 5.0

help(math.log)
## Help on built-in function log in module math:
##
## log(...)
##     log(x, [base=math.e])
##     Return the logarithm of x to the given base.
##
##     If the base not specified, returns the natural logarithm (base e) of x.

import math as mt # Similar to `mt = math`

print(mt.pi)
## 3.141592653589793

from math import *
print(pi, log(32, 2))
## 3.141592653589793 5.0
