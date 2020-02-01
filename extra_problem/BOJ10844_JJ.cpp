#include <iostream>
#include <cmath>

using namespace std;

long long int dp[101][11];
long long int ans=0;
int n;

int main()
{
    cin>>n;
    for(int j=1;j<10;j++) dp[1][j]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i][0] = dp[i-1][1] %1000000000;
        for(int x=1;x<=8;x++) {
            dp[i][x]=(dp[i-1][x+1]+dp[i-1][x-1])%1000000000;
        }
        dp[i][9] = dp[i-1][8] %1000000000;
    }
    for(int x=0;x<10;x++) ans = ans+dp[n][x];
    cout<<ans%1000000000;
    return 0;
}