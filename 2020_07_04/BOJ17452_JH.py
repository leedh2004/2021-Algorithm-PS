import sys

n = int(sys.stdin.readline())
chars = [[[1000,-1], [-1000,-1]] for _ in range(29)]

ans = 100
for i in range(n):
	string = input()
	
	for j in range(len(string)):
		index = ord(string[j])-97
		ans = min(ans, char[index][0][0]-(j-len(string))-1, j-char[index][1][0]-1)
	
	for j in range(len(string)):
		index = ord(string[j])-97
		if char[index][0][0] > j:
			char[index][0][0] = j
			char[index][0][1] = i
		if char[index][1][0] < j-len(string):
			char[index][1][0] = j-len(string)
			char[index][1][1] = i	

print(chars)

for i in range(28):
	if chars[i][0][2] == 0 and chars[i][1][2] == 0 and chars[i][0][1] == chars[i][1][1]:
		continue
	ans = min(ans, chars[i][0][0] - chars[i][1][0]-1)

if ans == 100:
	ans = -1
print(ans)