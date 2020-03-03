import sys

sys.setrecursionlimit(10**9)

"""
def check(arr):
	idx = -1
	for i in range(len(dp)):
		if dp[i][0] == arr:
			idx = i
			break
	return idx
"""
def palindrome(s, e):
	if (s, e) in dp:
		return dp.get((s, e))
	if s >= e:
		dp[(s, e)] = 0
		return 0

	if num[s] == num[e]:
		#dp[s][e] = palindrome(s + 1, e - 1)
		#dp.append([[s, e], palindrome(s+1, e-1)])
		dp[(s, e)] = palindrome(s+1, e-1)
	else :
		#dp[s][e] = min(palindrome(s, e - 1), palindrome(s + 1, e)) + 1
		#dp.append([[s, e],  min(palindrome(s, e - 1), palindrome(s + 1, e)) + 1])
		dp[(s, e)] = min(palindrome(s, e - 1), palindrome(s + 1, e)) + 1
	return dp.get((s, e))

N = int(sys.stdin.readline())
num = list(map(int, sys.stdin.readline().split()))

dp = dict()

print(palindrome(0, N - 1))