import sys

def init(node, start, end):
	if start == end:
		tree[node] = [num[start], num[start]]
	else :
		minA, maxA = init(node*2, start, (start+end)//2)
		minB, maxB = init(node*2+1, (start+end)//2+1, end)
		tree[node] = [min(minA, minB), max(maxA, maxB)]
	return tree[node]

def result(node, start, end, left, right):
	if left > end or right < start:
		return 1000000001, 0
	if left <= start and end <= right:
		return tree[node]

	minA, maxA = result(node*2, start, (start+end)//2, left, right)
	minB, maxB = result(node*2+1, (start+end)//2+1, end, left, right)   
	ret = [min(minA, minB), max(maxA, maxB)]
	return ret

n, m = map(int, sys.stdin.readline().split())
num = list()
tree = [0] * (n * 4)
for _ in range(n):
	num.append(int(input()))

init(1, 0, n-1)
for i in range(m):
	a, b = map(int, sys.stdin.readline().split())
	m, M = result(1, 0, n-1, a-1, b-1)
	print("{} {}".format(m, M))
