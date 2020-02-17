import sys

N = int(sys.stdin.readline())
vil = dict()
sum = 0
for i in range(N):
	a, b = map(int, sys.stdin.readline().split())
	vil.update({a : b})
	sum += b

vil = sorted(vil.items(), key=lambda item: item[0])
target, i = 0, 0
while target < (sum / 2):
	target += vil[i][1]
	i += 1
print(vil[i - 1][0])