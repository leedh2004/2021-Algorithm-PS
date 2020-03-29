N, C = map(int, input().split())
MOD = 1000000007
dp = [[0 for x in range(10001)] for y in range(N+1)]

max_c = 0
for i in range(2, N+1):
	max_c += i-1
	dp[i][0] = 1
	for j in range(1, min(10000, max_c)+1):
		dp[i][j] = (dp[i][j-1]%MOD + dp[i-1][j]%MOD)%MOD
		if j >= i:
			dp[i][j] = ((dp[i][j]%MOD)-(dp[i-1][j-i]%MOD)+MOD)%MOD

print(dp[N][C])