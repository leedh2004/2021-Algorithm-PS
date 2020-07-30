import sys

n, m = map(int, sys.stdin.readline().split())
board = [[] for y in range(n)]
for i in range(n):
	tmp = list(map(int, sys.stdin.readline().split()))
	board[i] = tmp


ans = 0
dp = [[[0, 0] for x in range(m)] for y in range(n)]
#Case 1 소수 출발
for i in range(n):
	dp[i][0][0] = board[i][0]
	dp[i][0][1] = board[i][0]

for j in range(m-1):
	for i in range(n):
		if (i+1) < n:
			#아래 방향 이동
			dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][1]+board[i+1][j+1])
		
		if (i-1) >= 0:
			#윗 방향 이동
			dp[i-1][j+1][0] = max(dp[i-1][j+1][0], dp[i][j][0] + board[i-1][j+1])
		
		dp[i][j+1][0] = max(dp[i][j+1][0], dp[i][j][1] + board[i][j+1])
		dp[i][j+1][1] = max(dp[i][j+1][1], dp[i][j][0] + board[i][j+1])

for i in range(n):
	ans = max(ans, dp[i][m-1][0], dp[i][m-1][1])


dp = [[[0, 0] for x in range(m)] for y in range(n)]
#Case 2 정수 출발
tmp = 0
for i in range(n):
	dp[i][0][0] = board[i][0]
	dp[i][0][1] = board[i][0]

for j in range(m-1):
	for i in range(n):
		#오른쪽 강제 이동
		dp[i][j+1][0] = max(dp[i][j+1][0], dp[i][j][1]+board[i][j+1])
		
		if (i+1) < n:
			#아래 방향 이동	
			dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][0]+board[i+1][j+1])
		
		if (i-1) >= 0:
			#윗 방향 이동
			dp[i-1][j+1][0] = max(dp[i-1][j+1][0], dp[i][j][0]+board[i-1][j+1])
		
		#오른쪽 선택 이동
		dp[i][j+1][1] = dp[i][j][0]+board[i][j+1]

for i in range(n):
	tmp = max(tmp, dp[i][m-1][0], dp[i][m-1][1])

ans = max(ans, tmp)
print(ans)