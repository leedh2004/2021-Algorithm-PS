#include <iostream>
#include <cstdio>

typedef long long int ll;

using namespace std;

int n,m,k;
ll dp[16][16];

void solve()
{
    for(int i=1;i<=n;i++) dp[i][1]=1;
    for(int i=1;i<=m;i++) dp[1][i]=1;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
}




int main()
{
    scanf("%d%d%d",&n,&m,&k);
    if(k==0) k=1;
    int mid_x,mid_y;
    mid_x= ((k-1)/m)+1;
    mid_y= k-((k-1)/m)*m;
    //printf("%d %d : \n", mid_x,mid_y);
    solve();
    //printf("%lld\n",dp[mid_x][mid_y]);
    //printf("%lld\n",dp[n-mid_x][m-mid_y]);
    printf("%lld\n",dp[mid_x][mid_y]*dp[n-mid_x+1][m-mid_y+1]);
    return 0;
}