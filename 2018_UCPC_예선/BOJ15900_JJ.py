import sys 

sys.setrecursionlimit(10000) 

def dfs(now_node,d):
    global dist,adj,n,ans,visited
    visited[now_node] = 1
    flag = False
    for i in adj[now_node]:
        #한개라도 있으면 자식노드가 아니다.
        if visited[i] == 0:
            flag = True
            dfs(i,d+1)
    if not flag:
        ans = ans + d



n = int(sys.stdin.readline())
adj = {}
visited = [0]*n
dist = [0]*n
ans = 0

for i in range(n-1):
    x,y = map(int,sys.stdin.readline().split())
    x = x - 1
    y = y - 1
    if x not in adj:
        adj[x] = [y]
    else : 
        adj[x].append(y)
    if y not in adj:
        adj[y] = [x]
    else : 
        adj[y].append(x)

dfs(0,0)

if ans%2==0:
    print("No")
else:
    print("Yes")