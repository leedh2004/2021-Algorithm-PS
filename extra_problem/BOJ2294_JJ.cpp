#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n,k;
long long cost[101];
int dp[10001];

struct str{
    long long c;
    int num;
};

str tmp;
queue <str> q;



int main()
{
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        cin>>cost[i];
        if(cost[i]<=k)
        {
            dp[cost[i]]=1;
            q.push({cost[i],1});
        }
    }
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(tmp.c==k) 
        {
            cout<<tmp.num;
            return 0;
        }
        for(int i=1;i<=n;i++)
        {
            if((tmp.c+cost[i])<=k&&dp[tmp.c+cost[i]]==-1)
            {
                dp[tmp.c+cost[i]]=tmp.num+1;
                q.push({tmp.c+cost[i],tmp.num+1});
            }
        }
    }
    cout<<"-1";
    return 0;
}