import sys
import copy

N, S, M = map(int, input().split())
V = list(map(int, input().split()))
V.insert(0, 0)
new, num = [S], list()

for i in range(1, N + 1):
	for j in range(len(new)):
		a = new[j] + V[i]
		b = new[j] - V[i]
		
		if 0 <= a and a <= M and a not in num:
			num.append(a)
		if 0 <= b and b <= M and b not in num:
			num.append(b)
	if len(num) == 0:
		print(-1)
		sys.exit()
	new = copy.deepcopy(num)
	num.clear()

print(max(new))