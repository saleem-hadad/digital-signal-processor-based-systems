from math import *

class Complex:
	def __init__(self, real, imaginary):
		self.real = real
		self.imaginary = imaginary

	def magnitude(self):
		return sqrt(self.real ** 2 + self.imaginary ** 2)

	def phase(self):
		return atan2(self.imaginary, self.real)

def IDFT(input):
	n = len(input)
	k = n / 2 + 1

	freqDomainSignal = []
	for i in range(k):
		real = 0
		imaginary = 0
		for j in range(n):
			real = real + input[j] * cos((2 * pi * i * j)/n)
			imaginary = imaginary - input[j] * sin((2 * pi * i * j)/n)

		freqDomainSignal.append(Complex(real, imaginary))

	return freqDomainSignal

input = [0.0, 1.0, 1.0, 1.0] # -> (3, 0) (-1, 0) (-1, 0)
output = IDFT(input) 
for wave in output:
	print(wave.real, wave.imaginary)

input = [0.0, 1.0, 2.0, 3.0, 4.0, 5.0] 
output = IDFT(input) 
for wave in output:
	print(wave.real, wave.imaginary)

input = [0.0, (1/sqrt(2)), 1.0, (1/sqrt(2)), 0, -(1/sqrt(2)), -1, -(1/sqrt(2))]
output = IDFT(input) 
for wave in output:
	print(wave.magnitude(), wave.phase())

input = [i/100.0 for i in range(100)]
print(input)
output = IDFT(input) 
for wave in output:
	print(wave.magnitude(), wave.phase())
