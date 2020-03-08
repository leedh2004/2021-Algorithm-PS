import sys

N, M = map(int, sys.stdin.readline().split())
num = list(map(int, sys.stdin.readline().split()))
sum = [0]
for i in range(1, N+1):
	sum.append(sum[i - 1] + num[i - 1])
for i in range(M):
	s, e = map(int, sys.stdin.readline().split())
	print(sum[e] - sum[s - 1])