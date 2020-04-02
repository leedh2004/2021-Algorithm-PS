import sys

sys.setrecursionlimit(10**6)

def dfs(index):
	if visited[index] == 1:
		return 0
	
	visited[index] = 1
	dp[index][1] += people[index]

	tlist = tree[index]
	for i in tlist:
		if visited[i] == 0:
			dfs(i)
			dp[index][1] += dp[i][0]
			dp[index][0] += max(dp[i][0], dp[i][1])

N = int(sys.stdin.readline())
people = list(map(int, sys.stdin.readline().split()))
people.insert(0, 0)
tree = [[] for y in range(N+1)]
for i in range(N-1):
	s, e = map(int, sys.stdin.readline().split())
	tree[s].append(e)
	tree[e].append(s)

dp = [[0 for x in range(2)] for y in range(N+1)]
visited = [0] * (N+1)
dfs(1)
print(max(dp[1][0], dp[1][1]))