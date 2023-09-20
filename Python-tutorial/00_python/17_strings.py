x = 'Pluto is a planet'
y = "Pluto is a planet"
print(x == y)
## True

# Indexing
planet = 'Pluto'
print(planet[0])
## P

# Slicing
print(planet[-3:])
## uto

# How long is this string?
print(len(planet))
## 5

# Yes, we can even loop over them
print([char + '! ' for char in planet])
## ['P! ', 'l! ', 'u! ', 't! ', 'o! ']

# ALL CAPS
claim = 'Pluto is a planet!'
print(claim.upper())
## PLUTO IS A PLANET!

# all lowercase
print(claim.lower())
## pluto is a planet!

# Searching for the first index of a substring
print(claim.index('plan'))
## 11

print(claim.startswith(planet))
## True

print(claim.endswith('dwarf planet'))
## False

position = 9
print("{}, you'll always be the {}th planet to me.".format(planet, position))
## Pluto, you'll always be the 9th planet to me.

pluto_mass = 1.303 * 10 ** 22
earth_mass = 5.9722 * 10 ** 24
population = 52910390
#                      2 decimal points 3 decimal points, format as percent    separate with commas
print("{} weighs about {:.2} kilograms ({:.3%} of Earth's mass). It is home to {:,} Plutonians.".format(
	planet, pluto_mass, pluto_mass / earth_mass, population,
))
## Pluto weighs about 1.3e+22 kilograms (0.218% of Earth's mass). It is home to 52,910,390 Plutonians.

# Referring to format() arguments by index, starting from 0
s = """Pluto's a {0}.
No, it's a {1}.
{0}!
{1}!""".format('planet', 'dwarf planet')
print(s)
## Pluto's a planet.
## No, it's a dwarf planet.
## planet!
## dwarf planet!
