numbers = {'one': 1, 'two': 2, 'three': 3}

print(numbers['one'])
## 1

numbers['eleven'] = 11
print(numbers)
## {'one': 1, 'two': 2, 'three': 3, 'eleven': 11}

numbers['one'] = 'Pluto'
print(numbers)
## {'one': 'Pluto', 'two': 2, 'three': 3, 'eleven': 11}

for k in numbers:
	print("{} = {}".format(k, numbers[k]))
## one = Pluto
## two = 2
## three = 3
## eleven = 11
