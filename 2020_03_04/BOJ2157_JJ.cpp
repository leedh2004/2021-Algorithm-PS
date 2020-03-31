#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n,m,k;
int dist[301];
int dp[301][301];
int cost[301][301];

int solve(int city, int mm)
{
    if(city==n) return 0;
    if(mm==m) return INT_MIN;
    if(dp[city][mm]!=0) return dp[city][mm];
    int ans=INT_MIN;
    for(int i=city+1;i<=n;i++)
    {
        if(cost[city][i]!=0) ans=max(ans,solve(i,mm+1)+cost[city][i]);
    }
    dp[city][mm]=ans;
    return dp[city][mm];
}

int main()
{
    int st,ed,c;
    scanf("%d%d%d",&n,&m,&k);
    while (k--)
    {
        scanf("%d%d%d",&st,&ed,&c);
        if(st<ed && cost[st][ed]<c) cost[st][ed]=c;
    }
    printf("%d\n",solve(1,1));
    return 0;
}