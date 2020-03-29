N = int(input())
cost = list(map(int, input().split()))
minimum = min(cost)
index = cost.index(minimum)
hands = int(input())
rst = list()
while hands >= minimum:
	rst.append(str(index))
	hands -= minimum

s = 0
for i in range(len(rst)):
	for j in range(N-1, -1, -1):
		if cost[j] <= hands + minimum:
			rst[i] = str(j)
			hands -= cost[j] - minimum
			break
	if rst[s] == '0':
		s += 1
		hands += minimum

if s == len(rst):
	print("0")
else :
	print(''.join(rst[s:]))