import sys
import math

#Python은 재귀에 제한이 1000이다 이걸 바꿔야 한다.
sys.setrecursionlimit(10**6)

"""summary 4963

	- 한 정사각형에서 가로, 세로 또는 대각선으로 연결이면 걸어갈 수 있는 사각형
	- 걸어갈 수 있는 사각형끼리는 하나의 섬으로 생각

	Input :
		첫번째 줄 : 0 < w, h <= 50  data type : int
		두번째 줄 부터 h 줄까지 : 1 -> land, 0 -> sea
		End of input : 0, 0

	Solution : 인접 행렬 DFS를 통한 그래프 탐색

	DFS : Depth-First Search(Graph searching algorithm)

	Root Nood에서 그래프를 타고 내려가다가 깊이를 기준으로 탐색하는 알고리즘
	
	인졉 행렬의 장점
		- 구현이 쉽다.
		- 노드 i와 노드 j가 연결되어 있는지 보고싶을 때 adj[i][j]이므로 시간복잡도 O(1)
	인접 행렬으 단점
		- 노드 i에 연결되어 있는 모든 노드들을 방문하고 싶을 때는 adj[i]를 다 봐야하므로 O(v)
"""

global w, h

#Check land's connection by DFS(recursion)
def checkConnection(land_map, visit_map, i, j):
	direction_x = [-1, -1, -1, 0, 0, 1, 1, 1]
	direction_y = [-1, 0, 1, -1, 1, -1, 0, 1]
	
	visit_map[i][j] = 1

	for k in range(len(direction_y)):
		new_x = j + direction_x[k]
		new_y = i + direction_y[k]

		#Check out of range in matrix
		if new_x >= w or new_x < 0 or new_y >= h or new_y < 0:
			continue
			
		if land_map[new_y][new_x] == 1 and visit_map[new_y][new_x] == 0:
			checkConnection(land_map, visit_map, new_y, new_x)


while True:
	w, h = map(int, input().split())

	if w == 0 and h == 0:
		break

	land_map = [[0 for x in range(w)] for y in range(h)]
	visit_map = [[0 for x in range(w)] for y in range(h)]	 

	cnt_land = 0

	for i in range(h):
		land_map[i] = list(map(int, input().split())) #Make map
		#map(a, b)는 b의 원소들을 a라는 지정된 형으로 변환시켜 준다.

	for i in range(h):
		for j in range(w):
			if visit_map[i][j] == 0 and land_map[i][j] == 1:				
				#Check land's connection
				checkConnection(land_map, visit_map, i, j)

				cnt_land += 1

	print(cnt_land)