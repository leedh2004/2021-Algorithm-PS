N, M = map(int, input().split())

answer = [['.' for i in range(N)] for j in range(M)]
for i in range(N):
	val = input()

	for j in range(len(val)):
		asci = int(ord(val[j]))
		
		if asci == 45:
			asci = 124
		elif asci == 124:
			asci = 45
		elif asci == 47:
			asci = 92
		elif asci == 92:
			asci = 47
		elif asci == 94:
			asci = 60
		elif asci == 60:
			asci = 118
		elif asci == 118:
			asci = 62
		elif asci == 62:
			asci = 94

		answer[M - j - 1][i] = chr(asci)

for i in range(M):
	for j in range(N):
		print(answer[i][j], end ="")

	print()