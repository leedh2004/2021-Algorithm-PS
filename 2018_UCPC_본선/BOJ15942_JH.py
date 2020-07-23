import sys
from collections import deque

def solve():
	n = int(sys.stdin.readline())
	k, p = map(int, sys.stdin.readline().split())


	used = [0] * (n+2)
	heap = [0] * (n+1)

	heap[p] = k
	used[k] = 1

	index = p // 2
	i = k - 1
	while index >= 1:
		if i == 0:
			print(-1)
			return 0
		heap[index] = i
		used[i] = 1
		i = i -1
		index = index // 2

	poss = deque([p*2, p*2+1])
	num = k+1
	while poss:
		index = poss.popleft()
		if index > n:
			break
		if num > n:
			print(-1)
			return 0
		heap[index] = num
		used[num] = 1
		num += 1

		poss.append(index*2)
		poss.append(index*2 +1)

	index = 1
	cnt = 1
	while index <= n:
		if heap[index] != 0:
			print(heap[index])
		else :
			while used[cnt] != 0:
				cnt += 1
			print(cnt)
			cnt += 1
		index += 1
			
if __name__ == "__main__":
	solve()
