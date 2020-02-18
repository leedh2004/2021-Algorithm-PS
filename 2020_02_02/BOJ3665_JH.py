import sys

def swap(a, b):
	if tpl_board[b][a]:
		tmp = a
		a = b
		b = tmp

	tpl_board[a][b] = 0
	tpl_board[b][a] = 1
	indegree[a] += 1
	indegree[b] -= 1

def checkError():
	if indegree.count(0) >= 2:
		return 1
	elif indegree.count(0) == 0:
		return 2
	return 0

def topological(num):
	indegree[num] = -1
	for i in range(len(tpl_board)):
		if tpl_board[num][i] == 1:
			indegree[i] -= 1

T = int(sys.stdin.readline())
while T > 0:
	T -= 1
	n = int(sys.stdin.readline())
	team = list(map(int, sys.stdin.readline().split()))

	tpl_board = [[0 for x in range(n)] for y in range(n)]
	indegree = [0 for x in range(n)]
	for i in range(n - 1):
		for j in range(i + 1, n):
			tpl_board[team[i] - 1][team[j] - 1] = 1
			indegree[team[j] - 1] += 1
	
	m = int(sys.stdin.readline())
	for _ in range(m):
		a, b = map(int, sys.stdin.readline().split())
		swap(a - 1, b - 1)

	queue, ans = [], []
	condition = 0
	while True:
		condition = checkError()
		if condition:
			break
		queue.append(indegree.index(0))
		ans.append(queue.pop(0))
		topological(ans[len(ans) - 1])
		if len(ans) == n:
			break

	if condition == 1:
		print("?")
	elif condition == 2:
		print("IMPOSSIBLE")
	else :
		for i in range(len(ans) - 1):
			print(ans[i]+1, end=" ")
		print(ans[len(ans) - 1] + 1)