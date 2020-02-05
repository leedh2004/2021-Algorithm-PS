import sys
import heapq

def findMiddle(num):
	if len(maxheap) == 0 or num < maxheap[0][1]:
		heapq.heappush(maxheap, (-1 * num, num))
	else :
		heapq.heappush(minheap, num)

	if len(minheap) > len(maxheap):
		rotate = heapq.heappop(minheap)
		heapq.heappush(maxheap, (-1 * rotate, rotate))
	elif len(minheap) + 1 < len(maxheap):
		rotate = heapq.heappop(maxheap)[1]
		heapq.heappush(minheap, rotate)

N = int(sys.stdin.readline())
minheap = []
maxheap = []

for i in range(N):
	number = int(sys.stdin.readline())
	findMiddle(number)
	print(maxheap[0][1])