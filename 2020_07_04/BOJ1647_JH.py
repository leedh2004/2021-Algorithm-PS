import sys

global village
global ans

class UnionFind:
	def __init__(self, n):
		self.home = [0] * (n+1)
		self.size = n
		for i in range(n+1):
			self.home[i] = i

	def find(self, a):
		if self.home[a] != a:
			return self.find(self.home[a])

		return a

	def union(self, a, b):
		finda = self.find(a)
		findb = self.find(b)

		if finda == findb:
			return False
		elif finda < findb:
			self.home[findb] = finda
		else :
			self.home[finda] = findb
		return True

def kruskal(n):
	global ans, village

	cnt = 0
	for s, e, w in road:
		if village.union(s, e):
			if cnt == n - 2:
				break
			ans += w
			cnt += 1

if __name__ == "__main__":
	n, m = map(int, sys.stdin.readline().split())
	village = UnionFind(n)
	road = []
	ans = 0
	for i in range(m):
		s, e, w = map(int, sys.stdin.readline().split())
		road.append((s, e, w))
		road.append((e, s, w))

	road = sorted(road, key=lambda x: x[2])
	kruskal(n)
	print(ans)

