#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

vector<int> adj[1000001];
vector<int> child[1000001];

int n,dp[1000001][2];
bool visited[1000001];

//재귀로 1을 기준으로한 트리와 각각의 child노드들을 구한다.
void get_child(int now)
{
    visited[now]=true;
    for(int i=0;i<adj[now].size();i++)
    {
        int next = adj[now][i];
        if(!visited[next])
        {
            child[now].push_back(next);
            get_child(next);
        }
    }
}



int get_dp(int now_node,bool ck)
{
    //이미 존재하는 값이라면 바로 return
    if(dp[now_node][ck]!=0) return dp[now_node][ck];

    //자식이 없는 노드일때 얼리어답터임을 나타내는 ck 값이 결과값이 된다.
    if(child[now_node].size()==0) return dp[now_node][ck]=ck;
    
    //만약 now_node가 얼리어답터라면 : 
    if(ck)
    {
        int ans=0;
        for(int i=0;i<child[now_node].size();i++) ans=ans+min(get_dp(child[now_node][i],true),get_dp(child[now_node][i],false));
        return dp[now_node][ck]=ans+1;
    }
    //now가 얼리어답터가 아니라면
    else
    {
        int ans=0;
        for(int i=0;i<child[now_node].size();i++) ans=ans+get_dp(child[now_node][i],true);
        return dp[now_node][ck]=ans;
    }
}


int main()
{
    int st,ed;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&st,&ed);
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    get_child(1);
    printf("%d",min( get_dp(1,false) , get_dp(1,true) ));
    return 0;
}