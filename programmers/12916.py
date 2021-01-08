def solution(s):
    val = 0 
    for c in s:
        if c == 'p' or c == 'P':
            val += 1
        elif c == 'y' or c == 'Y':
            val -= 1
    print(val)
    return val == 0

print(solution("pPoooyY"))
print(solution("Pyy"))

# def numPY(s):
#     # 함수를 완성하세요
#     return s.lower().count('p') == s.lower().count('y')