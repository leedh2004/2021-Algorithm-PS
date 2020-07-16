dirX = [0, 1, 1, 0, -1, -1]
dirY = [1, 1, -1, -1, -1, 1]

n = int(input())

stack = [[0,1]]
visited = [[0,1]]
cnt, curi = 0, 0
ans = 0

while stack:
	x, y = stack[len(stack)-1]

	for i in range(2):
		nx = x + dirX[(curi + 5 + 2*i)%6]
		ny = y + dirY[(curi + 5 + 2*i)%6]
		cnt += 1
		
		if [nx, ny] in visited and cnt != n:
			continue

		if [nx, ny] not in visited and cnt == n: