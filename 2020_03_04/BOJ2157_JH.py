N, M, K = map(int, input().split())
edge = [[0 for x in range(N+1)] for y in range(N+1)]
for i in range(K):
	s, e, w = map(int, input().split())
	if s > e:
		continue
	edge[s][e] = max(edge[s][e], w)

dp = [[-1 for x in range(N+1)] for y in range(N+1)]
dp[1][1] = 0
for s in range(1, N):
	for e in range(s, N+1):
		if edge[s][e] < 1:
			continue
		for i in range(1, M):
			if dp[s][i] == -1:
				continue
			dp[e][i+1] = max(dp[e][i+1], dp[s][i] + edge[s][e])

print(max(dp[N]))