#include <iostream>
#include <cstring>

using namespace std;

int n;
int dp[1001][10];
int ans=0;

int main()
{
    cin>>n;
    for(int i=0;i<=9;i++) dp[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=j;k++) dp[i][j]=(dp[i][j]+dp[i-1][k])%10007;
        }
    }
    for(int i=0;i<=9;i++) ans= (ans+dp[n][i])%10007;
    cout<<ans;
    return 0;
}