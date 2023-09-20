primes = [2, 3, 5, 7]

planets = ['Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune']

hands = [
	['J', 'Q', 'K'],
	['2', '2', '2'],
	['6', 'A', 'K'], # (Comma after the last element is optional)
]

# (I could also have written this on one line, but it can get hard to read)
hands = [['J', 'Q', 'K'], ['2', '2', '2'], ['6', 'A', 'K']]

my_favorite_things = [32, 'raindrops on roses', help]
# (Yes, Python's help function is *definitely* one of my favorite things)

print('planets[0]', planets[0])       # 'Mercury'
print('planets[1]', planets[1])       # 'Venus'
print('planets[-1]', planets[-1])     # 'Neptune'
print('planets[-2]', planets[-2])     # 'Uranus'
print('planets[0:3]', planets[0:3])   # ['Mercury', 'Venus', 'Earth']
print('planets[:3]', planets[:3])     # ['Mercury', 'Venus', 'Earth']
print('planets[3:]', planets[3:])     # ['Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune']
print('planets[1:-1]', planets[1:-1]) # ['Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus']

planets[3] = 'Malacandra'
print(planets)
## ['Mercury', 'Venus', 'Earth', 'Malacandra', 'Jupiter', 'Saturn', 'Uranus', 'Neptune']

planets[:3] = ['Mur', 'Vee', 'Ur']
print(planets)
## ['Mur', 'Vee', 'Ur', 'Malacandra', 'Jupiter', 'Saturn', 'Uranus', 'Neptune']

# That was silly. Let's return them to their original names
planets[:4] = ['Mercury', 'Venus', 'Earth', 'Mars']
print(planets)
## ['Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune']

# How many planets are there?
print(len(planets))
## 8

# Pluto is a planet, darn it!
planets.append('Pluto')
print(planets)
## ['Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune', 'Pluto']

print(planets.index('Earth'))
## 2

print('Earth' in planets)
## True

print(planets.index('Europa'))
# Throws ValueError: 'Europa' is not in list
