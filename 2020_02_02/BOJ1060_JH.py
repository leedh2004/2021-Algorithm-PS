import sys
import heapq
import math

L = int(sys.stdin.readline())
input_list = list(map(int, sys.stdin.readline().split()))
input_list.insert(0, 0)
N = int(sys.stdin.readline())
count = {}

for i in range(1, L + 1):
	count[input_list[i]] = 0
input_list.sort()	

for i in range(len(input_list) - 1):
	dis = input_list[i + 1] - input_list[i] - 1
	if dis == 1:
		count[input_list[i] + 1] = 0
	elif dis == 0:
		continue
	elif dis <= N:
		for j in range(1, math.ceil(dis/2) + 1):
			count[input_list[i] + j] = j * (dis + 1 - j) - 1 
			count[input_list[i + 1] - j] = j * (dis + 1 - j) - 1
	elif dis > N:
		for j in range(1, math.ceil(N/2) + 1):
			count[input_list[i] + j] = j * (dis + 1 - j) - 1
			count[input_list[i + 1] - j] = j * (dis + 1 - j) - 1

count = list(sorted(count.items(), key=lambda item: (item[1], item[0])))
for i in range(min(N, len(count))):
	print(count[i][0], end=" ")
for i in range(N - len(count)):
	print(input_list[L] + i + 1, end=" ")