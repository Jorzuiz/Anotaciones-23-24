planets = ['Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune']

planet_to_initial = {planet: planet[0] for planet in planets}
print(planet_to_initial)
## {'Mercury': 'M', 'Venus': 'V', 'Earth': 'E', 'Mars': 'M', 'Jupiter': 'J', 'Saturn': 'S', 'Uranus': 'U', 'Neptune': 'N'}

for planet, initial in planet_to_initial.items():
	print("{} begins with \"{}\"".format(planet.rjust(10), initial))
##   Mercury begins with "M"
##     Venus begins with "V"
##     Earth begins with "E"
##      Mars begins with "M"
##   Jupiter begins with "J"
##    Saturn begins with "S"
##    Uranus begins with "U"
##   Neptune begins with "N"
