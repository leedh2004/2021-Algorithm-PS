"""
N = int(input())
child = list()
child.insert(0, 0)
for i in range(N):
	child.append(int(input()))

chk = [0] * (N+1)
chk[1] = 0
ans = 0
max_index = 0
for i in range(2, N+1):
	complete_cnt = 0
	for j in range(1, i):
		if chk[j] == 1:
			continue
		if child[j] > child[i]:
			complete_cnt += 1
			max_index = j
	if complete_cnt == 1:
		chk[max_index] = 1
		ans += 1
	elif complete_cnt > 1:
		chk[i] = 1
		ans += 1

print(ans)
"""

N = int(input())
child = list()
child.insert(0, 0)
for i in range(N):
	child.append(int(input()))

dp = [1] *(N+1)
for i in range(1, N+1):
	for j in range(1, i):
		if child[i] > child[j]:
			dp[i] = max(dp[i], dp[j] + 1)

print(N - max(dp))