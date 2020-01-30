def dfsStack(m, n):
	stack = []
	area = 1
	visit[n][m] = 1
			
	dfs_x = [-1, 0, 1, 0]
	dfs_y = [0, -1, 0, 1]

	stack.append([m, n])

	while len(stack) != 0:
		dfs_list = stack.pop()
		x = dfs_list[0]
		y = dfs_list[1] 

		for i in range(4):
			nx = x + dfs_x[i]
			ny = y + dfs_y[i]

			if 0 <= nx and 0 <= ny and nx < len(arr[0]) and ny < len(arr):
				if arr[ny][nx] == 0 and visit[ny][nx] == 0:
					visit[ny][nx] = 1
					area += 1
					stack.append([nx, ny])

	area_list.append(area)

m, n, k = map(int, input().split())

arr = [[0 for x in range(n)] for y in range(m)]
visit = [[0 for x in range(n)] for y in range(m)]
area_list = list()

for _ in range(k):
	x1, y1, x2, y2 = map(int, input().split())

	for i in range(y1, y2):
		for j in range(x1, x2):
			arr[i][j] = 1

for i in range(m):
	for j in range(n):
		if arr[i][j] == 0 and visit[i][j] == 0:
			dfsStack(j, i)

area_list.sort()
print(len(area_list))
for i in area_list:
	print(i, end=" ")