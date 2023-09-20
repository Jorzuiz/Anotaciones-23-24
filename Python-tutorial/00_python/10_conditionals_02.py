print(bool(1)) # All numbers are treated as true, except 0
print(bool(0))
print(bool('asf')) # All strings are treated as true, except the empty string ""
print(bool(''))

## True
## False
## True
## False

# Generally empty sequences (strings, lists, and other types we've yet to see like lists)
# are "falsey" and the rest are "truthy".

if 0:
	print(0)
elif 'spam':
	print('spam')
## spam
