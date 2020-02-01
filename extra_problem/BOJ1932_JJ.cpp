#include <iostream>
#include <cmath>

using namespace std;

long long int ans=0;
int n;
int table[501][501];
long long int dp[501][501];


void cal()
{
    dp[1][1]=table[1][1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j==1) dp[i][j]=dp[i-1][j]+table[i][j];
            else if(j==i) dp[i][j] = dp[i-1][j-1]+table[i][j];
            else dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]) + table[i][j];
            //cout<<dp[i][j]<<" ";
            ans=max(ans,dp[i][j]);
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++) cin>>table[i][j];
    }
    cal();
    cout<<ans;
    return 0;
}