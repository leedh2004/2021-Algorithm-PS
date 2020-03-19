from itertools import permutations
import math

num = [0] * 10000000
num[2] = 2
num[0] = -1
for i in range(3, 9999999, 2):
	num[i] = i

for i in range(3, math.floor(math.sqrt(9999999)), 2):
	if num[i] == i:
		for j in range(i*i, 9999999, i):
			if num[j] == j:
				num[j] = i

c = int(input())
for i in range(c):
	check = list()
	ans = 0
	st = input()
	item = list(set(list(map(''.join, permutations(list(st))))))
	for j in range(len(item)):
		for k in range(1, len(item[j])+1):
			sli = int(item[j][0:k])
			if num[sli] == sli and sli not in check:
				ans += 1
				check.append(sli)
	print(ans)