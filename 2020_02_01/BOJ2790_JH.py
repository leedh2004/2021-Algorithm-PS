import sys

N = int(sys.stdin.readline())
score = list()
for _ in range(N):
	score.append(int(sys.stdin.readline()))

score.sort(reverse=True)
target, cnt = 0, 0
for i in range(N):
	target = max(target, score[i] + i + 1)
	if score[i] + N >= target:
		cnt += 1
print(cnt)