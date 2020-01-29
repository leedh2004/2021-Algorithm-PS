import sys
import collections

dy = [-1, 0, 1, 0, 2, 1, -1, -2, -2, -1, 1, 2]
dx = [0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1]

k = int(sys.stdin.readline())
w, h = map(int, sys.stdin.readline().split())
board = list()

for _ in range(h):
    input_list = list(map(int, sys.stdin.readline().split()))
    board.append(input_list)

d = [[[0]*(k+1) for _ in range(w)] for _ in range(h)]

def bfs():
    q = collections.deque()
    q.append((0, 0, 0))
    while q:
        y, x, z = q.popleft()

        #말처럼 움직일 수 있는 지 없는지 판단
        j = 4 if z == k else 12

        #상황 종료
        if y == h - 1 and x == w - 1:
            print(d[y][x][z])
            return
        
        for i in range(j):
            nx, ny = x + dx[i], y + dy[i]
            nz = z if i < 4 else z + 1
            
            if nx < 0 or nx >= w or ny < 0 or ny >= h:
                continue
            if not d[ny][nx][nz] and not board[ny][nx]:
                d[ny][nx][nz] = d[y][x][z] + 1
                q.append((ny, nx, nz))
    print(-1)

bfs()