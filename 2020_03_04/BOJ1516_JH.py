import sys
from collections import deque

sys.setrecursionlimit(10**6)

N = int(sys.stdin.readline())

degree = [0] * (N+2)
edge = [[] for y in range(N+2)]
time = [0] * (N+2)
for i in range(1, N+1):
	get = list(map(int, input().split()))
	time[i] += get[0]
	for j in range(1, len(get)-1):
		degree[i] += 1
		edge[get[j]].append(i)

queue = deque()
for i in range(N):
	if degree[i] == 0:
		queue.append(i)

ans = [0] * (N+2)
while len(queue) != 0:
	s = queue.popleft()
	ans[s] += time[s]
	for i in edge[s]:
		degree[i] -= 1
		ans[i] = max(ans[i], ans[s])
		if degree[i] == 0:
			queue.append(i)

for i in range(1, N+1):
	print(ans[i])