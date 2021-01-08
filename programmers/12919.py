def solution(seoul):
    for (idx, val) in enumerate(seoul):
        if val == 'Kim':
            return "김서방은 " + str(idx) + "에 있다"

solution(['Jane', 'Kim'])

# return "김서방은 {}에 있다".format(seoul.index('Kim'))