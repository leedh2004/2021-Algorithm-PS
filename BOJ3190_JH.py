import sys
import collections

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]
snake = collections.deque()

def movingSnake(direction):
	[y, x] = snake[0]
	ny = y + dy[direction]
	nx = x + dx[direction]

	if nx <= 0 or nx >= len(board) or ny <= 0 or ny >= len(board):
		return False

	if [ny, nx] in snake:
		return False

	if board[ny][nx] == 0:
		[end_y, end_x] = snake.pop()

	snake.appendleft([ny, nx])
	return True

def moving(move, L):
	time = 0
	index = 0
	direction = 1

	while True:
		if index < L:
			if move[index][0] == time:
				if move[index][1] == "D":
					direction = (direction + 1) % 4
				else :
					direction = (direction + 3) % 4
				index += 1

		if movingSnake(direction) == False:
			print(time + 1)
			return
		
		time += 1


if __name__ == '__main__':
	N = int(sys.stdin.readline())
	K = int(sys.stdin.readline())

	board = [[0 for x in range(N + 1)] for y in range(N + 1)]
	for _ in range(K):
		y, x = map(int, sys.stdin.readline().split())
		board[y][x] = 1

	L = int(sys.stdin.readline())
	move = list()
	for _ in range(L):
		X, C = sys.stdin.readline().split()
		move.append([int(X), C])

	snake.append([1, 1])
	moving(move, L)
