import sys

N, M = map(int, sys.stdin.readline().split())
time = list(map(int, sys.stdin.readline().split()))

if N <= M:
	print(N)
	sys.exit()

left = 0;
right = 2000000000 * 30
ans = -1
while left <= right:
	mid = (left + right) //2
	child = M

	for i in range(M):
		child += (mid // time[i])

	if child >= N:
		ans = mid
		right = mid - 1
	else :
		left = mid + 1

before = ans
child = M
for i in range(M):
	child += ((before-1) // time[i])

cnt, i = 0, 0
for i in range(M):
	if before % time[i] == 0:
		child += 1
	if child == N:
		print(i+1)
		break