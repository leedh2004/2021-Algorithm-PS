import sys

n, m = map(int, sys.stdin.readline().split())
group = [[] for _ in range(m+1)]
info = [[] for _ in range(n+1)]
able = [1] * (m+1)
for i in range(1, m+1):
	temp = list(map(int, sys.stdin.readline().split()))
	for j in range(1, len(temp)):
		info[temp[j]].append(i)
		group[i].append(temp[j])
ans = [1] * (n+1)


mutant = list(map(int, sys.stdin.readline().split()))

for i in range(len(mutant)):
	if mutant[i] == 0:
		ans[i+1] = 0
		for j in info[i+1]:
			able[j] = 0
			for k in group[j]:
				ans[k] = 0

if sum(ans) == 1:
	print("NO")
else :
	print("YES")
	for i in range(1, len(ans)):
		print(ans[i], end=" ")
