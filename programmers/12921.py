def solution(n):
    answer = 0
    isPrime = [True for i in range(n+1)]
    isPrime[0] = isPrime[1] = False
    for i in range(2, n+1):
        for j in range(2 * i, n+1, i):
            isPrime[j] = False
    for b in isPrime:
        if b:
            answer += 1
    return answer

print(solution(10))
print(solution(5))

# def solution(n):
#     num=set(range(2,n+1))

#     for i in range(2,n+1):
#         if i in num:
#             num-=set(range(2*i,n+1,i))
#     return len(num)
