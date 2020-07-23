import sys

string = ["sukhwan", "baby", "sukhwan", "tu", "tu", "very", "cute", "tu", "tu", "in", "bed", "tu", "tu", "baby"]
n = int(sys.stdin.readline())
quota = n // 14
n = n % 14

print(string[n], end="")

if n % 4 == 3 and n < 12:
	if 2+quota < 5:
		print("ru" * (2+quota))
	else :	
		print("+ru*%d" %(2+quota))
if n != 0 and n % 4 == 0 and n <= 12:
	if 1+quota < 5:
		print("ru" * (1+quota))
	else :
		print("+ru*%d" %(1+quota))
