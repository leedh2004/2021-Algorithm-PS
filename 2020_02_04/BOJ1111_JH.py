import sys

def error():
	print("B")
	sys.exit()

N = int(sys.stdin.readline())
num = list(map(int, sys.stdin.readline().split()))

if N <= 2:
	if N == 2 and num[0] == num[1]:
		print(num[0])
	else :
		print("A")
	sys.exit()

if num[0] == num[1] or num[1] == num[2]:
	for i in range(1, N - 1):
		if num[i] != num[i + 1]:
			error()
	print(num[1])
else :
	a = (num[2] - num[1]) // (num[1] - num[0]) 
	for i in range(N - 2):
		if num[i + 1] == num[i + 2]:
			error()
		a1 = (num[i + 2] - num[i + 1]) // (num[i + 1] - num[i])
		if a != a1 or (num[i + 2] - num[i + 1]) % (num[i + 1] - num[i]) != 0:
			error()
	b = num[1] - num[0]*a
	print(num[N - 1]*a + b)