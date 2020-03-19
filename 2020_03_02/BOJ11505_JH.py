import sys

def init(node, start, end):
	if start == end:
		tree[node] = num[start]
	else :
		tree[node] = (init(node*2, start, (start+end)//2) * init(node*2+1, (start+end)//2+1, end))%1000000007
	return tree[node]

def mul(node, start, end, left, right):
	if left > end or right < start:
		return 1
	if left <= start and end <= right:
		return tree[node]
	ret = (mul(node*2, start, (start+end)//2, left, right)*mul(node*2+1, (start+end)//2+1, end, left, right))%1000000007
	return ret

def update(node, start, end, index, diff):
	if index < start or index > end:
		return 0
	if start == end:
		tree[node] = diff % 1000000007
	else :
		update(node*2, start, (start+end)//2, index, diff)
		update(node*2+1, (start+end)//2+1, end, index, diff)
		tree[node] = (tree[node*2] * tree[node*2+1]) % 1000000007

N, M, K = map(int, input().split())

num = list()
for i in range(N):
	num.append(int(input()))

tree = [1] * (N*4)
init(1, 0, N-1)

for i in range(M+K):
	a, b, c = map(int, input().split())
	if a == 1:
		diff = c
		num[b-1] = diff
		update(1, 0, N-1, b-1, diff)
	else :
		ans = mul(1, 0, N-1, b-1, c-1)
		print(int(ans))