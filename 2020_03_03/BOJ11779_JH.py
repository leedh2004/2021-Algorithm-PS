import heapq

n = int(input())
m = int(input())

dp = [1000000000] *(n+1)
p = [100001] * (n+1)
edge = [[] for y in range(n+1)]
for i in range(m):
	s, e, w= map(int, input().split())
	edge[s].append([e, w])

start, target = map(int, input().split())
dp[start] = 0
p[start] = start
heap = []
heapq.heappush(heap, (0, start))
while len(heap) != 0:
	(wei, s) = heapq.heappop(heap)
	if dp[s] < wei:
		continue
	for i in range(len(edge[s])):
		[e, w] = edge[s][i]
		if dp[e] > dp[s] + w:
			dp[e] = dp[s] + w
			heapq.heappush(heap, (dp[e], e))
			p[e] = s

cnt = 0
ans = [target]
print(dp[target])
while start != target:
	ans.append(p[target])
	target = p[target]

print(len(ans))
for i in range(len(ans)-1, -1, -1):
	print(ans[i], end=" ")
print("")