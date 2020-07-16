import math

N = int(input())

cord = [[0 for x in range(2)] for y in range(N)]
for i in range(N):
	x, y = map(int, input().split())
	cord[i] = [x, y]

distance = [[0 for x in range(2)] for y in range(N)]
for i in range(N):
	for j in range(N):
		if i == j:
			continue
		
		if distance[i][0] < pow(cord[i][1]-cord[j][1], 2)+pow(cord[i][0]-cord[j][0], 2):
			distance[i][0] = pow(cord[i][1]-cord[j][1], 2)+pow(cord[i][0]-cord[j][0], 2)
			distance[i][1] = j

rst_index = 0
for i in range(N):
	if distance[i][0] < distance[rst_index][0]:
		rst_index = i

print("%d %d" %(cord[rst_index][0], cord[rst_index][1]))