import sys

num = [0] * 1000000
for i in range(3, 1000000, 2):
	num[i] = i

for i in range(3, 1000, 2):
	if num[i] == i:
		for j in range(i*i, 1000000, i):
			if num[j] == j:
				num[j] = i

prime = list()
for i in range(3, 1000000, 2):
	if num[i] == i:
		prime.append(i)

while True:
	T = int(sys.stdin.readline())
	if T == 0:
		break

	for i in range(len(prime)):
		if T - prime[i] == num[T-prime[i]]:
			print("%d = %d + %d" %(T, prime[i], T - prime[i]))
			break