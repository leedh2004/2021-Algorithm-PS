#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> adj[100001];
bool visted[100001];
int N,R,Q;
int ans[100001];

int solve(int now_node)
{
    visted[now_node]=true;
    for(int i=0;i<adj[now_node].size();i++)
    {
        if(!visted[adj[now_node][i]])ans[now_node]=ans[now_node]+solve(adj[now_node][i]);
    } 
    ans[now_node]++;
    return ans[now_node];
}

int main()
{
    int st,ed,tmp;
    scanf("%d%d%d",&N,&R,&Q);   
    for(int i=1;i<N;i++)
    {
        scanf("%d%d",&st,&ed);
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    solve(R);
    while (Q--)
    {
        scanf("%d",&tmp);
        printf("%d\n",ans[tmp]);
    }
    return 0;
}