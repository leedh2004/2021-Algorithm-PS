import sys
sys.setrecursionlimit(10**6)

def gcd(degree1=360, degree2=360):
	if degree1 % degree2 == 0:
		return degree2
	else :
		return gcd(degree2, degree1 % degree2)

N, K = map(int, sys.stdin.readline().split())
degree = list(map(int, sys.stdin.readline().split()))
target = list(map(int, sys.stdin.readline().split()))
min_deg = 360

for i in degree:
	min_deg = gcd(min_deg, gcd(degree2=i))

for a in target:
	if a % min_deg == 0:
		print("YES")
	else :
		print("NO")