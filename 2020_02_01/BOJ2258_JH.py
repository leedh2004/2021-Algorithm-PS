import sys

N, M = map(int, sys.stdin.readline().split())
M = -1 * M
meat = [(0, 0)]
for _ in range(N):
	w, p = map(int, sys.stdin.readline().split())
	meat.append((-1 * w, p))
	
meat = sorted(meat, key=lambda x: (x[1], x[0]))
sum, price = 0, 0
for i in range(1, len(meat)):
	sum += meat[i][0]
	price = price + meat[i][1] if meat[i][1] == meat[i - 1][1] else 0
	if sum <= M:
		print(meat[i][1] + price)
		break

if sum > M:
	print(-1)