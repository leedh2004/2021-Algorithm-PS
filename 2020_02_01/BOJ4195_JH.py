import sys

def getParent(string):
	if parent[string] == string: 
		return string
	else :
		p = getParent(parent[string])
		parent[string] = p
		return p

def unionParent(string1, string2):
	a = getParent(string1)
	b = getParent(string2)

	if a != b:
		parent[b] = a
		count[a] += count[b]

if __name__=="__main__":
	T = int(sys.stdin.readline())
	for _ in range(T):
		F = int(sys.stdin.readline())
		parent = {}
		count = {}
		
		for _ in range(F):
			string1, string2 = map(str, sys.stdin.readline().split())
			if string1 not in parent:
				parent[string1] = string1
				count[string1] = 1

			if string2 not in parent:
				parent[string2] = string2
				count[string2] = 1
			unionParent(string1, string2)
			print(count[getParent(string1)])