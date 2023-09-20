import matplotlib.pyplot as plt
import numpy as np

def main():
	X = np.linspace(-np.pi, np.pi, 256)
	C, S = np.cos(X), np.sin(X)
	plt.plot(X, C, color="blue", linewidth=2.5, linestyle="-", label="cosine")
	plt.plot(X, S, color="red", linewidth=2.5, linestyle="-", label="sine")

	# Set x limits
	plt.xlim(-4., 4.)
	# Set x ticks
	plt.xticks(np.linspace(-4, 4, 9))

	# Set y limits
	plt.ylim(-1.2, 1.2)
	# Set y ticks
	plt.yticks(np.linspace(-1, 1, 5))

	ax = plt.gca() # gca stands for 'get current axis'
	ax.spines['right'].set_color('none')
	ax.spines['top'].set_color('none')
	ax.xaxis.set_ticks_position('bottom')
	ax.spines['bottom'].set_position(('data', 0))
	ax.yaxis.set_ticks_position('left')
	ax.spines['left'].set_position(('data', 0))

	plt.legend(loc='upper left')

	# Show the result on the screen
	plt.show()

main()
