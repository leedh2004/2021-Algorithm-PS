import sys
sys.setrecursionlimit(10**6)

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

def Dfs(y, x, cnt):
	if cnt == 4:
		return board[y][x]

	sum = 0
	for i in range(4):
		ny = y + dy[i]
		nx = x + dx[i]

		if 0 <= ny and ny < len(board) and 0 <= nx and nx < len(board[0]):
			if visited[ny][nx] == False:
				visited[ny][nx] = True
				sum = max(sum, board[y][x] + Dfs(ny, nx, cnt + 1))
				visited[ny][nx] = False

	return sum

def middle(y, x):
	ret = 0
	if y >= 1 and x >= 1 and x < len(board[0]) - 1:
		ret = max(ret, board[y][x - 1] + board[y][x] + board[y - 1][x] + board[y][x + 1])
	if y >= 1 and y < len(board) - 1 and x < len(board[0]) - 1:
		ret = max(ret, board[y - 1][x] + board[y][x] + board[y][x + 1] + board[y + 1][x])
	if y >= 0 and y < len(board) - 1 and x < len(board[0]) - 1:
		ret = max(ret, board[y][x - 1] + board[y][x] + board[y + 1][x]+ board[y][x + 1])
	if y >= 1 and y < len(board) - 1 and x >= 1:
		ret = max(ret, board[y - 1][x] + board[y][x] + board[y][x - 1] + board[y + 1][x])
	return ret

N, M = map(int, sys.stdin.readline().split())
board = list()
for _ in range(N):
	input_list = list(map(int, sys.stdin.readline().split()))
	board.append(input_list)

visited = [[0 for x in range(M)] for y in range(N)]
ret = 0
for y in range(N):
	for x in range(M):
		visited[y][x] = True
		ret = max(ret, Dfs(y, x, 1))
		ret = max(ret, middle(y, x))
		visited[y][x] = True

print(ret)
