#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int n,ans;
int people[10001];
bool visited[10001];
int dp[10001][2];
vector<int> adj[10001];
vector<int> one_way[10001];

void make_one_way(int now_node)
{
    visited[now_node]=true;
    for(int i=0;i<adj[now_node].size();i++)
    {
        if(!visited[adj[now_node][i]])
        {
            make_one_way(adj[now_node][i]);
            one_way[now_node].push_back(adj[now_node][i]);
        }
    }
    return ;
}

int solve(int now_node, bool flag)
{
    //메모제이션
    if(dp[now_node][flag]!=-1) return dp[now_node][flag];
    //재귀 종료조건
    if(one_way[now_node].size()==0)
    {
        if(flag) dp[now_node][flag]=people[now_node];
        else dp[now_node][flag]=0;
        return dp[now_node][flag];
    }
    int tmp=0;
    for(int i=0;i<one_way[now_node].size();i++)
    {
        if(flag) tmp = tmp + solve(one_way[now_node][i],!flag);
        else tmp = tmp + max( solve(one_way[now_node][i],!flag),solve(one_way[now_node][i],flag) );
    }
    if(flag) tmp=tmp+people[now_node];
    dp[now_node][flag]=tmp;
    return dp[now_node][flag];
}

int main()
{
    int st,ed;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&people[i]);
    for(int i=1;i<n;i++){
        scanf("%d%d",&st,&ed);
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    memset(dp,-1,sizeof(dp));
    make_one_way(1);
    printf("%d",max(solve(1,false), solve(1,true) ) );
    return 0;
}