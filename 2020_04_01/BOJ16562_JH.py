def find(index):
	if index == parent[index]:
		return index

	parent[index] = find(parent[index])
	return parent[index]

def merge(u, v):
	u = find(u)
	v = find(v)
	if u == v:
		return 1
	if cost[u] < cost[v]:
		parent[v] = u
	else :
		parent[u] = v

N, M, k = map(int, input().split())
cost = list(map(int, input().split()))
cost.insert(0, 0)

parent = [0 for y in range(N+1)]
for i in range(1, N+1):
	parent[i] = i

for i in range(M):
	u, v = map(int, input().split())
	merge(u, v)

ans = 0
for i in range(1, N+1):
	if parent[i] == i:
		ans += cost[i]

if ans <= k:
	print(ans)
else :
	print("Oh no")