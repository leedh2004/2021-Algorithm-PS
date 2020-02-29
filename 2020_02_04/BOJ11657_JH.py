import sys
import copy

def machine(arr):
	for i in range(len(bus)):
		[[s, e], w] = bus[i]
		if arr[s] != 1000000000:
			arr[e] = min(arr[e], arr[s] + w)

N, M = map(int, sys.stdin.readline().split())
bus = list()
d = [1000000000] * N
d[0] = 0

for i in range(M):
	A, B, C = map(int, sys.stdin.readline().split())
	A, B = A - 1, B - 1
	if bus.count([A, B]) == 1 and bus[bus.index[A, B]][1] > C:
		bus[bus.index[A, B]][1] = C
	else :
		bus.append([[A, B], C])

for _ in range(N - 1):
	machine(d)

n = copy.deepcopy(d)
machine(n)

if n != d:
	print(-1)
else :
	for i in range(1, len(d)):
		if d[i] == 1000000000:
			print(-1)
		else :
			print(d[i])