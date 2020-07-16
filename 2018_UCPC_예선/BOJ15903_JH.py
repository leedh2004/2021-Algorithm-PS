import heapq

n, m = map(int, input().split())
num = list(map(int, input().split()))
heapq.heapify(num)

for i in range(m):
	a = heapq.heappop(num)
	b = heapq.heappop(num)
	heapq.heappush(num, a+b)
	heapq.heappush(num, a+b)

print(sum(num))