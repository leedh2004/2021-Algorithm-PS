import sys

N, M = map(int, sys.stdin.readline().split())
tree = list(map(int, sys.stdin.readline().split()))
high = max(tree)

left, right = 0, high
ans = 0

while left <= right:
	mid = (left + right) // 2
	total = 0

	for i in range(N):
		if mid < tree[i]:
			total += tree[i] - mid

	if total >= M:
		if ans < mid:
			ans = mid
		left = mid + 1
	else :
		right = mid - 1

print(ans)