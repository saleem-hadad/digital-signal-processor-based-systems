from math import *

class Complex:
	def __init__(self, real, imaginary):
		self.real = real
		self.imaginary = imaginary

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
	print(wave.real, wave.imaginary)
