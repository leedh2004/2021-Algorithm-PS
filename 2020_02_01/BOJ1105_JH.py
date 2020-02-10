import sys

L, R = map(str, sys.stdin.readline().split())
cnt = 0
if len(L) == len(R):
	for i in range(len(L)):
		if L[i] == R[i]: 
			if L[i] == "8" and R[i] == "8":
				cnt += 1	
		else :
			break
print(cnt)