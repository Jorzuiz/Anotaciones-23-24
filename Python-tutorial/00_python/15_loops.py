planets = ['Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune']

for planet in planets:
	print(planet, end=' ') # Print all on same line
## Mercury Venus Earth Mars Jupiter Saturn Uranus Neptune

# Let's separate the lines...
print()

multiplicands = (2, 2, 2, 3, 3, 5)
product = 1
for mult in multiplicands:
	product = product * mult

print(product)
## 360

s = 'steganograpHy is the practicE of conceaLing a file, message, image, or video within another fiLe, message, image, Or video.'
for char in s:
	if char.isupper():
		print(char, end='')
## HELLO

# Let's separate the lines...
print()

for i in range(5):
	print("Doing important work, i = ", i)
## Doing important work, i =  0
## Doing important work, i =  1
## Doing important work, i =  2
## Doing important work, i =  3
## Doing important work, i =  4

i = 0
while i < 10:
	print(i, end=' ')
## 0 1 2 3 4 5 6 7 8 9
