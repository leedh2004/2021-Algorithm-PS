import sys
import heapq

def error():
	print(-1)
	sys.exit()

def isAvailable(a):
	if a == 1000000000:
		a = -1
	return a

def dijkstra(node1, node2, node3=-1):
	size = len(edge)
	d = [1000000000] * size
	heap = []

	d[node1] = 0
	heapq.heappush(heap, (0, node1))

	while len(heap) != 0:
		(wei, n) = heapq.heappop(heap)
		if d[n] < wei:
			continue
		for i in range(1, size):
			if edge[n][i] < 1001 and d[i] > d[n] + edge[n][i]:
				d[i] = d[n] + edge[n][i]
				heapq.heappush(heap, (d[n] + edge[n][i], i))

	a = isAvailable(d[node2])
	b = isAvailable(d[node3])
	return [a, b]

N, E = map(int, sys.stdin.readline().split())
edge = [[1001 for x in range(N + 1)] for y in range(N + 1)]

for i in range(E):
	a, b, c = map(int, sys.stdin.readline().split())
	edge[a][b] = min(edge[a][b], c)
	edge[b][a] = edge[a][b]
p1, p2 = map(int, sys.stdin.readline().split())

[w1, w2] = dijkstra(1, p1, p2)
[w3, w4] = dijkstra(N, p1, p2)
[w5, w6] = dijkstra(p1, p2)
if w5 == -1 or w3 == -1 or w5 == -1:
	error()
ans = min(w1 + w5 + w4, w2 + w5 + w3)
print(ans)