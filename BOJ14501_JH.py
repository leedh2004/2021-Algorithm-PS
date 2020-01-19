import sys

n = int(sys.stdin.readline())

time = list()
price = list()

for _ in range(n):
	t, p = map(int, sys.stdin.readline().split())
	time.append(t)
	price.append(p)

dp = [[0 for x in range(n)] for y in range(n)] 
for i in range(n):
	if i >= time[0] - 1:
		dp[0][i] = price[0]

for i in range(1, n):
	for j in range(n):
		if j >= time[i] + i - 1 and i + time[i] <= n and j >= i:
			dp[i][j] = max(dp[i - 1][i - 1] + price[i], dp[i - 1][j])
		else :
			dp[i][j] = dp[i - 1][j]

print(dp[n - 1][n - 1])