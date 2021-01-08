def solution(strings, n):
    answer = []
    for (i, v)in enumerate(strings):
        strings[i] = v[n] + v
    strings.sort()
    for s in strings:
        answer.append(s[1:])
    return answer

#  sorted(strings, key=lambda x: x[n])