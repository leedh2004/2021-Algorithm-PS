from collections import deque
import sys

graph = {}

n = int(sys.stdin.readline())
for i in range(n-1):
	a, b = map(int, sys.stdin.readline().split())

	if a not in graph:
		graph[a] = [b]
	else :
		graph[a].append(b)
	
	if b not in graph:
		graph[b] = [a]
	else :
		graph[b].append(a)

queue = deque([[1, 0]])
ans = 0
visited = [0] * (n+1)

while queue:
	bf, lev = queue.popleft()
	visited[bf] = 1
	
	chk = 0
	for i in graph[bf]:
		if visited[i] == 1:
			continue

		queue.append([i, lev+1])
		chk += 1

	if chk == 0:
		ans += lev

if ans % 2 == 0:
	print("No")
else : 
	print("Yes")
