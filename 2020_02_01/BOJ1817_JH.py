import sys

N, M = map(int, sys.stdin.readline().split())
if N == 0:
	print("0")
	sys.exit()
book = list(map(int, sys.stdin.readline().split()))
cnt, weight = 1, 0

for i in range(len(book)- 1, -1, -1):
	if weight + book[i] > M:
		weight = book[i]
		cnt += 1
	elif weight + book[i] == M:
		weight = 0
		if i != 0:
			cnt += 1
	else :
		weight += book[i]
print(cnt)