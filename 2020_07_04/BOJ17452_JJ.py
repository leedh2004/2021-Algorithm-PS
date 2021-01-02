import sys

n = int(sys.stdin.readline())
front = [[] for _ in range(26)]
back = [[] for _ in range(26)]

alpha = "abcdefghijklmnopqrstuvwxyz"
alpha_dict = {}
for i in range(26):
    alpha_dict[alpha[i]] = i

for i in range(n):
    word = sys.stdin.readline()
    length = len(word)-1
    for j in range(length):
        front[alpha_dict[word[j]]].append([j,i])
        back[alpha_dict[word[j]]].append([length-j-1,i])

ans = 50
for i in range(26):
    if front[i] and back[i]:

        #정렬
        front[i].sort()
        back[i].sort()

        for j in range(len(back[i])):
            if front[i][0][1] != back[i][j][1] :
                ans = min(ans,front[i][0][0] + back[i][j][0])
                break

        for j in range(len(front[i])):
            if back[i][0][1] != front[i][j][1] :
                ans = min(ans,back[i][0][0] + front[i][j][0])
                break

if ans==50:
    print(-1)
else :
    print(ans)





