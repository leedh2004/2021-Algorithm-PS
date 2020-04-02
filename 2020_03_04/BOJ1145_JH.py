import sys

list = list(map(int, sys.stdin.readline().split()))
num = 1
while True:
	cnt = 0
	for i in range(len(list)):
		if num >= list[i] and num % list[i] == 0:
			cnt += 1

	if cnt >= 3:
		print(num)
		break
	num += 1