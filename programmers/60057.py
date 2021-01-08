def compress(s,l):
    words = [s[i:i+l] for i in range (0, len(s), l)]
    print(words)

def solution(s):
    for i in range(1, len(s) // 2 + 1):
        compress(s, i)

print(len("ababcdcdababcdcd"))
print(solution("aabbaccc"))
print(solution("ababcdcdababcdcd"))
print(solution("abcabcdede"))