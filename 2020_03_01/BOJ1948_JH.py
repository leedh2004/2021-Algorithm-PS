from collections import deque

n = int(input())
m = int(input())
road = [[] for y in range(n + 1)]
back = [[] for y in range(n + 1)]
indegree = [0] * (n+1)
ans = [0] * (n+1)

for i in range(m):
	a, b, c = map(int, input().split())
	road[a].append([b, c])
	back[b].append([a, c])
	indegree[b] += 1

s, e = map(int, input().split())
queue = deque([s])
indegree[0] = -1
while len(queue) != 0:
	p = queue.popleft()
	indegree[p] = -1
	for i in range(len(road[p])): 
		[r, w] = road[p][i]	
		if ans[r] < ans[p] + w:
 			ans[r] = ans[p] + w
		indegree[r] -= 1
	if indegree.count(0) == 0:
		break
	queue.append(indegree.index(0))

q = [e]
cnt, chk = 0, 0
while cnt < len(q):
	p = q[cnt]
	for i in range(len(back[p])):
		[r, w] = back[p][i]
		if ans[p] - w == ans[r]:
			chk += 1
			if r not in q:
				q.append(r)
	cnt += 1

print(ans[e])
print(chk)