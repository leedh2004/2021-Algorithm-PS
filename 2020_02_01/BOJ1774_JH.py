import sys
import math
import heapq

def findUFO(a):
	if a == ufo[a]:
		return a
	else :
		u = findUFO(ufo[a])
		ufo[a] = u
		return u

def union(a, b):
	a = findUFO(a)
	b = findUFO(b)

	if a != b:
		ufo[b] = a
		return 1
	return 0

N, M = map(int, sys.stdin.readline().split())

pos= []
ufo = []
for i in range(N):
	pos.append(list(map(int, sys.stdin.readline().split())))
	ufo.append(i)
for _ in range(M):
	s, e = map(int, sys.stdin.readline().split())
	union(s - 1, e - 1)

dis = []
for i in range(N):
	for j in range(i + 1, N):
		a = pos[i][0] - pos[j][0]
		b = pos[i][1] - pos[j][1]
		heapq.heappush(dis, (math.sqrt((a ** 2) + (b ** 2)), [i, j]))

cnt = M
ans = 0
while len(dis) != 0 and cnt != N - 1:
	p = heapq.heappop(dis)
	min_d = p[0]
	old_p = p[1][0]
	new_p = p[1][1]
	if union(old_p, new_p):
		ans += min_d
		cnt += 1

print("%.2f" %ans)