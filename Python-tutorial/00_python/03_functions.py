from operator import le


def least_difference(a, b, c):
	"""
	Return the smallest difference between any two numbers among a, b, and c.

	>>> least_difference(1, 5, -5)
	4
	"""

	diff1 = abs(a - b)
	diff2 = abs(b - c)
	diff3 = abs(a - c)
	return min(diff1, diff2, diff3)

print(
	least_difference(1, 10, 100),
	least_difference(1, 10, 10),
	least_difference(5, 6, 7), # Python allows trailing commas in argument lists
)
