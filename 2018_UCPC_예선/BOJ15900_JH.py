import math
import sys

n = int(sys.stdin.readline())

chk = n
ans = n + 1
cnt = 0

for i in range(2, math.ceil(math.sqrt(n))+1):
	div = n / i
	ans += (chk - math.ceil(div)) * i + math.ceil(n / i)
	cnt += (chk - math.ceil(div)) + 1
	chk = math.ceil(div)
print(ans)
print(n - cnt)
ans -= (n - cnt) * math.ceil(math.sqrt(n))
print(ans)
