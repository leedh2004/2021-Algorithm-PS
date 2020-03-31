#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

//i:시작점, j:도착점
int cost[1000001],rcost[1000001],dp[1000001];
int ans,t,n;

int find_max(int arr[])
{
    int M=0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        if(dp[i-1]+arr[i]>0)
        {
            dp[i]=dp[i-1]+arr[i];
        }
        else dp[i]=0;
        M=max(M,dp[i]);
    }
    return M;
}


int main()
{
    
    scanf("%d",&t);
    while (t--)
    {
        int total=0,ans=0;
        scanf("%d",&n);
        memset(cost,0,sizeof(cost));
        memset(cost,0,sizeof(rcost));
        //input each city cost
        for(int i=1;i<=n;i++) {
            scanf("%d",&cost[i]);
            rcost[i]=-cost[i];
            total=total+cost[i];
        }
        //printf("%d %d %d\n",find_max(cost),total,find_max(rcost));

        printf("%d\n",max(find_max(cost),total+find_max(rcost)));
    }
    return 0;
}
