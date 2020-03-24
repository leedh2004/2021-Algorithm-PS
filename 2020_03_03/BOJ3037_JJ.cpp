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


/*
#include <bits/stdc++.h>
using namespace std;
int cache[1001][10001] {0,};
constexpr int MOD = 1'000'000'007;

int main()
{
    int n, c;
    scanf("%d %d", &n, &c);

    int limit = 0;
    for(int i=2; i<=n; ++i){
        limit += i-1;
        cache[i][0] = 1;
        int j = 1;
        while (j<=min(10000,limit)){
            cache[i][j] = (cache[i][j-1]%MOD + cache[i-1][j]%MOD)%MOD;
            printf("dp[%d][%d] : %d\n",i,j,cache[i][j]);
            printf("dp[2][2] : %d\n",cache[2][2]);
            if(j-i>=0) cache[i][j] = ((cache[i][j]%MOD)-(cache[i-1][j-i])+MOD)%MOD;
            printf("dp[%d][%d] : %d\n",i,j,cache[i][j]);
            ++j;
        }
    }

    printf("%d", cache[n][c]);
}
*/