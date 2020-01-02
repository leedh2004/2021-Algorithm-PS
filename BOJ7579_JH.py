"""summarize 7579

	7579 : 앱

		- 앱들은 User가 이전 작업들을 불러 올 때 빠른 처리를 위해 메모리 상에 활성화 됨
		- 활성화 되어 있는 앱들이 많아지면 정해져 있는 핸드폰 메모리 용량이 부족
		- 비활성화 된 앱을 불러오면 좋지 않다. 스마트하게 앱을 제거해야 한다.

		Ai : N개의 앱 중 i번쨰
		Mi : Ai앱의 메모리 크기
		Ci : Ai를 비활성화 후 다시 실행할 때 추가적으로 들어가는 수치

		이때 앱 B를 실행 해서 메모리 M바이트가 필요할 때 비활성화 한 앱들의 Ci의
		합을 최소화 하여 메모리 M바이트 확보해라

	Input case :
		첫 줄 : 정수 N, M (1 <= N <= 100, 1 <= M <= 10000000)
		둘째 줄 : m1 ~ mn의 N개의 정수 (1 <= m <= 10000000)
		셋쨰 줄 : C1 ~ Cn의 N개의 정수 (1 <= C <= 100)

	Solve : Dynamic Programming
"""
def application():
	n, m = map(int, input().split())

	memory = list(map(int, input().split()))
	cost = list(map(int, input().split()))

	dp = [[0 for x in range(sum(cost) + 1)] for y in range(n)]

	for i in range(cost[0], sum(cost) + 1):
		dp[0][i] = memory[0]

	for i in range(1, n):
		for j in range(sum(cost) + 1):
			if j >= cost[i] and dp[i - 1][j] <= dp[i - 1][j - cost[i]] + memory[i]:
				dp[i][j] = dp[i - 1][j - cost[i]] + memory[i]
			else:
				dp[i][j] = dp[i - 1][j]

	for i in range(sum(cost) + 1):
		for j in range(n):
			if dp[j][i] >= m:
				print(i)
				return 0

application()