import sys

n = int(sys.stdin.readline())
ans= ["","#","##"]

temp = 2
while temp < n:
	temp = temp * 2
	tstr = ans[-1]
	tstr = tstr + ("#" * ((temp//2)//2)) + ("." * ((temp//2)//2))
	ans.append(tstr)

a = temp // 2
temp = n - (temp//2) - 1
anstr = list(ans[-1])
if temp >= (a // 2):
	anstr[a:] = ans[-2]
	temp = temp - 1
index = 0

while temp > 0:
	if anstr[index] == '.':
		temp -= 1
		anstr[index] = '#'

	index += 1

if n == 1:
	print("#")
else :
	anstr = ''.join(anstr)
	print(anstr)
