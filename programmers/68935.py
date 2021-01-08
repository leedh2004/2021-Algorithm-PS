
def numToThird(n):
    ret = ""
    while n != 0:
        ret = str(n % 3) + ret
        n = n // 3
    return ret

def ThirdtoNum(third):
    l = len(third)
    ret = 0
    for i in range(0, l):
        ret += 3 ** (l - 1 - i) * int(third[i])
    return ret 

def solution(n):
    answer = numToThird(n)[::-1]
    return ThirdtoNum(answer)

print(solution(125))