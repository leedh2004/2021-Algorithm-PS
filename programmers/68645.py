def solution(n):
    b = [[ 0 for i in range(n) ] for i in range(n)]
    ret = []
    y = -1
    x = 0
    num = 1
    for i in range(n):
        for j in range(i, n):
            if i % 3 == 0:
                y += 1
            elif i % 3 == 1:
                x += 1
            elif i % 3 == 2:
                x -= 1
                y -= 1
            b[y][x] = num
            num += 1
    print(b)
    for y in range(n):
        for x in range(n):
            if b[y][x] != 0 :
                ret.append(b[y][x])
    return ret

print(solution(4))
print(solution(5))