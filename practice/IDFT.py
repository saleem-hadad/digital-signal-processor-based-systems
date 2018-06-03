from math import *
import numpy as np

class Complex:
	def __init__(self, real, imaginary):
		self.real = real
		self.imaginary = imaginary

def IDFT(input):
	k = len(input)
	n = (k - 1) * 2

	timeDomainSignal = np.zeros(n)

	for i in range(k):
		input[i].real = input[i].real * 2 / n
		input[i].imaginary = -input[i].imaginary * 2 / n

	input[0].real = input[0].real / 2
	input[k-1].real = input[k-1].real / 2

	for i in range(n):
		for j in range(k):
			real 	  = input[j].real * cos((2 * pi * i * j)/n)
			imaginary = input[j].imaginary * sin((2 * pi * i * j)/n)
			timeDomainSignal[i] = timeDomainSignal[i] + real + imaginary

	return timeDomainSignal

input = [Complex(3.0, 0.0), Complex(-1.0, 0.0), Complex(-1.0, 0.0)]
print(IDFT(input)) # 0 1 1 1

input = [Complex(15.0, 0.0), Complex(-3.0, 5.196153), Complex(-3.0, 1.732051), Complex(-3.0, 0.0)]
print(IDFT(input)) # 0 1 2 3 4 5