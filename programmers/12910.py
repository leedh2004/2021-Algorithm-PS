def solution(arr, divisor):
    answer = []
    for i in range(len(arr)):
        if arr[i] % divisor == 0:
            answer.append(arr[i])
    answer.sort()
    if len(answer) == 0:
        answer = [-1]
    return answer

print(solution([5,9,7,10], 5))
print(solution([2,36,1,3], 1))
print(solution([3,2,6], 10))


# def solution(arr, divisor): return sorted([n for n in arr if n%divisor == 0]) or [-1]

# def solution(arr, divisor):
#     arr = [x for x in arr if x % divisor == 0];
#     arr.sort();
#     return arr if len(arr) != 0 else [-1];
