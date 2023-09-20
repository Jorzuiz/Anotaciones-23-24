x = 0.125
print(x.as_integer_ratio())
## (1, 8)

numerator, denominator = x.as_integer_ratio()
print(numerator / denominator)
## 0.125

a = 1
b = 0
a, b = b, a
print(a, b)
## 0 1
