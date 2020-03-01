import sys

num = list(map(int, sys.stdin.readline().rstrip()))

dp = [[0 for x in range(len(num))] for y in range(len(num))]
if num[0] == 0:
	print(0)
	sys.exit()
dp[0][0] = 1

for i in range(1, len(num)):
	if num[i] == 0:
		if num[i - 1] * 10 + num[i] <= 27 and num[i - 1] != 0:
			if i == 1:
				dp[0][i] = 1
			else :
				dp[0][i] = dp[0][i - 2]
		else :
			print(0)
			sys.exit()
	else :
		if num[i - 1] * 10 + num[i] >= 27 or num[i - 1] * 10 + num[i] < 10:
			dp[0][i] = dp[0][i - 1]
		else :
			if i != 1:
				dp[0][i] = dp[0][i - 1] + dp[0][i - 2]
			else :
				dp[0][i] = 2

print(dp[0][len(num) - 1] % 1000000)