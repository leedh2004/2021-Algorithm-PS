import collections


def DFS(x,y,bi,turn,visited):
    global n,mv0,mv1,ans
    if turn>=n:
        return

    for i in range(3):
        #지나온 인덱스와 동일할때
        if bi == i:
            continue
        if (x+y)%2 == 0:
            #지나가지 않은 곳으로 이동
            if visited[x+mv0[i][0]][y+mv0[i][1]] == 0:
                visited[x+mv0[i][0]][y+mv0[i][1]] = 1
                DFS(x+mv0[i][0], y+mv0[i][1] ,i,turn+1,visited)
                visited[x+mv0[i][0]][y+mv0[i][1]] = 0
            #맞춰서 멈춰선경우
            else:
                if turn == n-1:
                    ans = ans + 1

        else :
            #지나가지 않은 곳으로 이동
            if visited[x+mv1[i][0]][y+mv1[i][1]] == 0:
                visited[x+mv1[i][0]][y+mv1[i][1]] = 1
                DFS(x+mv1[i][0], y+mv1[i][1] ,i,turn+1,visited)
                visited[x+mv1[i][0]][y+mv1[i][1]] = 0
            #맞춰서 멈춰선경우
            else:
                if turn == n-1:
                    ans = ans + 1

q = collections.deque()
n = int(input())
ans = 0
nx,ny = 50,50
visited = [[0]*100 for _ in range(100)]

# (x+y)%2 == 0 일때는 위 왼 오, 1일때는 아래 왼 오
mv0=[[1,0],[0,-1],[0,1]]
mv1=[[-1,0],[0,1],[0,-1]]

visited[50][50] = 1
visited[51][50] = 1
DFS(51,50,0,0,visited)
print(ans)
