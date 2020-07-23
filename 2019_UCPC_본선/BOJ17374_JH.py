import sys

t = int(sys.stdin.readline())
for i in range(t):
	coin = 0
	p, q, a, b, c, d = map(int, sys.stdin.readline().split())

	coin += (q // c) * d
	ans, i = 0, 0
	if p > coin:
		ans += coin
		p -= coin
		i = p // (a+b)
		ans += max(b*(i), p-a*(i+1) )
	else : 
		ans += p
		coin -= p
		i = coin // (a+b)
		ans += max(coin - b*(i+1), a*i)
	
	if ans < 0:
			ans = 0
	print(ans)  
