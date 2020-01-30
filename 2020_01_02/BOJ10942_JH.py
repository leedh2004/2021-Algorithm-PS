import sys

n = int(sys.stdin.readline())
input_list = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())

dp = [[0 for x in range(n)] for y in range(n)]
dp[n - 1][0] = 1

for i in range(n - 1):
	dp[i][0] = 1

	if input_list[i] == input_list[i + 1]:
		dp[i][1] = 1

for length in range(2, n):
	for s in range(n):
		e = s + length
		if e >= n :
			continue
		if input_list[s] == input_list[e] and dp[s + 1][length - 2] == 1:
			dp[s][length] = 1
		else :
			dp[s][length] = 0
 
for _ in range(m):
	s, e = map(int, sys.stdin.readline().split())
	print(dp[s - 1][e - s])