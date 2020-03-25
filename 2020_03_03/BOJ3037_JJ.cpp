#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n,c;
int dp[1001][10001];
const int MOD=1000000007;

int main()
{
    int j_index=0;
    scanf("%d%d",&n,&c);
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=1;
        j_index=i*(i-1)/2;
        for(int j=1;j<=min(j_index,10000);j++)
        {
            dp[i][j]= (dp[i-1][j]%MOD+dp[i][j-1]%MOD)%MOD;
            if(j>=i) dp[i][j]=( ( dp[i][j]%MOD) -(dp[i-1][j-i]%MOD) + MOD )%MOD;
        }
    }
    printf("%d",dp[n][c]);
    return 0;
}
