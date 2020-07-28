import sys

n, m = map(int, sys.stdin.readline().split())
ans = [1 for _ in range(n)] 
group = []
group_mutant = []
flag = True

for i in range(1, m+1):
    temp = list(map(int, sys.stdin.readline().split()))
    group.append(temp[1:])

mutant = list(map(int, sys.stdin.readline().split()))
ans = mutant[:]

group_stack = group[:]

#ans배열 생성
while group_stack:
    recent_group = group_stack.pop()

    #감염여부
    group_infected = True
    
    #한사람이라도 감염이 안되어 있으면 모두 감염 안된거임
    for person in recent_group:
        if ans[person-1]==0:
            group_infected = False
            break

    group_mutant.append(group_infected)
    if not group_infected:
        for person in recent_group:
            ans[person-1]=0

ans_check = ans[:]
group_mutant.reverse()

for idx in range(len(group)):
    #감염되었을때
    if group_mutant[idx]:
        for person in group[idx]:
            ans_check[person-1] = 1


# print(ans_check)
    

if ans_check == mutant:
    print("YES")
    for i in ans:
        print(i,end=" ")
    print("")
else :
    print("NO")





