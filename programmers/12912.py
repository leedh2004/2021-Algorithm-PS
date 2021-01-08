def solution(a, b):
    answer = 0
    r = sorted([a, b])
    for i in range(r[0], r[1]+1):
        answer += i 
    return answer

print(solution(3,5))

# def adder(a, b):
#     return (abs(a-b)+1)*(a+b)//2

# # 아래는 테스트로 출력해 보기 위한 코드입니다.
# print( adder(3, 5))

# def adder(a, b):
#     # 함수를 완성하세요
#     if a > b: a, b = b, a

#     return sum(range(a,b+1))

# # 아래는 테스트로 출력해 보기 위한 코드입니다.
# print( adder(3, 5))