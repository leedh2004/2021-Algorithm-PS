import sys

T = int(sys.stdin.readline())
for i in range(T):
	ans = 0
	num = list(map(int, sys.stdin.readline().split()))
	dp = [0] * (num[0]+1)
	for j in range(1, num[0]+1):
		dp[j] = min(dp[j-1] + num[j], num[j])
		
	ans = sum(num) - num[0] - min(dp)
	
	for j in range(1, num[0]+1):
		dp[j] = max(dp[j-1] + num[j], num[j])

	ans = max(ans, max(dp))
	print(ans)