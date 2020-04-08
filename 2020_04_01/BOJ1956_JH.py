V, E = map(int, input().split())
dis = [[1000000000 for x in range(V+1)] for y in range(V+1)]
for i in range(E):
	s, e, w = map(int, input().split())
	dis[s][e] = min(dis[s][e], w)

for mid in range(1, V+1):
	for s in range(1, V+1):
		for e in range(1, V+1):
			if dis[s][e] > dis[s][mid] + dis[mid][e]:
				dis[s][e] = dis[s][mid] + dis[mid][e]

ans = 1000000000
for i in range(1, V+1):
	ans = min(ans, dis[i][i])

if ans == 1000000000:
	print(-1)
else :
	print(ans)