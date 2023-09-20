import numpy as np
import matplotlib.pyplot as plt

def main():
	X = np.linspace(-np.pi, np.pi, 256)
	C, S = np.cos(X), np.sin(X)
	plt.plot(X, C)
	plt.plot(X, S)
	plt.show()
	# plt.savefig('image.jpg')

main()
