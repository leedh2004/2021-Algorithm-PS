#include <cstdio>
#include <iostream>

using namespace std;

int n,dp[201],arr[201];
int ans=1;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==0) dp[i]=1;
        for(int j=1;j<i;j++)
        {
            if(arr[i]>arr[j] && dp[i] <= dp[j]+1) 
            {
                dp[i]=dp[j]+1;
            }
        }
        ans=max(ans,dp[i]);
    }
    printf("%d",n-ans);
    return 0;
}