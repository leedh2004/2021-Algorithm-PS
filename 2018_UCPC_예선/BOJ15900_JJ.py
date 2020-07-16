import sys 
sys.setrecursionlimit(10000) 

def dfs(now_node,d,visited):
    global dist,adj,n,ans
    visited[now_node] = 1
    flag = False
    for i in range(n):
        #한개라도 있으면 자식노드가 아니다.
        if adj[now_node][i] == 1 and visited[i] == 0:
            flag = True
            dfs(i,d+1,visited)
    if not flag:
        ans = ans + d

n = int(input())
adj = [[0]*n for _ in range(n)]
visited = [0]*n
dist = [0]*n
ans = 0

for i in range(n-1):
    x,y = map(int,input().split())
    adj[x-1][y-1] = 1
    adj[y-1][x-1] = 1

dfs(0,0,visited)
if ans%2==0:
    print("No")
else:
    print("Yes")
