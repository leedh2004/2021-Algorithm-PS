def lcs(str1, str2, str3):
	dp = [[[0 for x in range(len(str3)+1)] for y in range(len(str2)+1)] for z in range(len(str1)+1)]
	for i in range(1, len(str1)+1):	
		for j in range(1, len(str2)+1):
			for k in range(1, len(str3)+1):
				if str1[i-1] == str2[j-1] and str1[i-1] == str3[k-1]:
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1
				else :
					dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k-1])

	return dp[len(str1)][len(str2)][len(str3)]

str1 = input()
str2 = input()
str3 = input()

ret = lcs(str1, str2, str3)
print(ret)