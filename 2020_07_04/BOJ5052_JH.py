import sys

class Node:
	def __init__(self, key):
		self.key = key
		self.child = {}

class Trie:
	def __init__(self):
		self.root = Node(None)

	def insert(self, s):
		curr = self.root

		for i in s:
			if i not in curr.child:
				curr.child[i] = Node(i)
			curr = curr.child[i]
		curr.child["*"] = Node("*")

	def search(self, s):
		curr = self.root

		for i in s:
			if "*" in curr.child:
				return True
			
			if i not in curr.child:
				return False
			
			curr = curr.child[i]

		return True

def solve():
	n = int(sys.stdin.readline())
	chk = False
	trie = Trie()

	for i in range(n):
		string = input()
		if trie.search(string):
			chk = True
		trie.insert(string)

	if chk:
		print("NO")
	else :
		print("YES")

if __name__ == "__main__":
	t = int(sys.stdin.readline())
	while t:
		t -= 1
		solve() 