import sys

n, k = map(int, input().split())
d = [[100000 for x in range(n+1)] for y in range(n+1)]
for i in range(k):
	s, e = map(int, input().split())
	d[s][e] = 1
	
for mid in range(1, n+1):
	for s in range(1, n+1):
		for e in range(1, n+1):
			if d[s][e] > d[s][mid] + d[mid][e]:
				d[s][e] = d[s][mid] + d[mid][e]
				
c = int(input())
for i in range(c):
	s, e = map(int, input().split())
	if d[s][e] != 100000:
		print(-1)
	elif d[e][s] != 100000:
		print(1)
	else :
		print(0)