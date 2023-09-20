squares = [n ** 2 for n in range(10)]
print(squares)
## [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]

squares = []
for n in range(10):
	squares.append(n ** 2)
print(squares)
## [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]

planets = ['Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune']
short_planets = [planet for planet in planets if len(planet) < 6]
print(short_planets)
## ['Venus', 'Earth', 'Mars']

loud_short_planets = [planet.upper() + '!' for planet in planets if len(planet) < 6]
print(loud_short_planets)
## ['VENUS!', 'EARTH!', 'MARS!']

def count_negatives(nums):
	"""
	Return the number of negative numbers in the given list.

	>>> count_negatives([5, -1, -2, 0, 3])
	2
	"""

	n_negative = 0
	for num in nums:
		if num < 0:
			n_negative = n_negative + 1
	return n_negative

def count_negatives(nums):
	return len([num for num in nums if num < 0])
