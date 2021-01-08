def solution(numbers):
    answer = []
    length = len(numbers)
    for i in range(length):
        for j in range(i+1, length):
            val = numbers[i] + numbers[j]
            if val not in answer:
                answer.append(val)
    answer.sort()
    return answer
print(solution([2,1,3,4,1]))