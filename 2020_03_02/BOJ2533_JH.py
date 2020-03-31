import sys

sys.setrecursionlimit(10**6)

def dfs(index):
	if visited[index] == 1:
		return 0
	visited[index] = 1
	dp[index][0] = 0
	dp[index][1] = 1

	link = tree[index]
	for i in link:
		if visited[i] == 0:
			dfs(i)
			dp[index][0] += dp[i][1]
			dp[index][1] += min(dp[i][1], dp[i][0])

N = int(sys.stdin.readline())
tree = [[] for y in range(N+1)]
for i in range(N-1):
	u, v = map(int, sys.stdin.readline().split())
	tree[u].append(v)
	tree[v].append(u)

dp = [[0 for x in range(2)] for y in range(N+1)]
visited = [0] * (N+1)
dfs(1)
print(min(dp[1][0], dp[1][1]))