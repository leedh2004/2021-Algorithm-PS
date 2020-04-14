#include <iostream>
#include <cstdio>

using namespace std;
 
int dp[1111][33][3];
int cost[1111][3];
int t,w,tmp;
int main()
{
    scanf("%d%d", &t, &w);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &tmp);
        cost[i][tmp] = 1;
    }
    dp[1][0][1] = cost[1][1];
    dp[1][1][2] = cost[1][2];
    int ans = max(dp[1][0][1],dp[1][1][2]);
    for (int i = 2; i <= t; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + cost[i][1];
            dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + cost[i][2];
            ans = max(ans, dp[i][j][1]);
            ans = max(ans, dp[i][j][2]);
        }
    }
    printf("%d", ans);
    return 0;
}