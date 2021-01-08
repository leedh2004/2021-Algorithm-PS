def solution(s):
    l = len(s)
    if l == 4 or l == 6:
        for c in s:
            if c < '0' or c > '9':
                return False
    else:
        return False
    return True

#    return s.isdigit() and len(s) in (4, 6)