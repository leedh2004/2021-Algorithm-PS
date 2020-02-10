import sys

N, M = map(int, sys.stdin.readline().split())
if N == 0:
	sys.exit()
book = list(map(int, sys.stdin.readline().split()))
cnt, weight = 1, 0

for i in range(len(book)):
	if weight + book[i] > M:
		weight = book[i]
		cnt += 1
	elif weight + book[i] == M:
		weight = 0
		if i != len(book) - 1:
			cnt += 1
	else :
		weight += book[i]
print(cnt)