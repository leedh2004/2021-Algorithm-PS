import sys
import heapq

T = int(input())

for i in range(T):
	n, m, t = map(int, input().split())
	s, g, h = map(int, input().split())
	candidate = list()
	edge = [[1001 for x in range(n + 1)] for y in range(n + 1)]
	check = [0] * (n + 1)

	for i in range(m):
		a, b, d = map(int, input().split())
		edge[a][b] = min(edge[a][b], d)
		edge[b][a] = edge[a][b]
	for i in range(t):
		candidate.append(int(input()))
	candidate.sort()

	heap = []
	d = [1000000000] * (n + 1)
	d[s] = 0

	heapq.heappush(heap, (0, s))
	while len(heap) != 0:
		(wei, p) = heapq.heappop(heap)
		if d[p] < wei:
			continue
		for i in range(len(edge)):
			if edge[p][i] < 1001 and d[i] >= d[p] + edge[p][i]:
				if d[i] == d[p] + edge[p][i]:
					check[i] = max(check[p], check[i])
				else :
					check[i] = check[p]
				d[i] = d[p] + edge[p][i]
				if (p == g and i == h) or (p == h and i == g):
					check[i] = 1
				heapq.heappush(heap, (d[i], i))
	for i in range(t):
		if check[candidate[i]] == 1:
			print(candidate[i], end= " ")
	if check.count(1) > 0:
		print("")