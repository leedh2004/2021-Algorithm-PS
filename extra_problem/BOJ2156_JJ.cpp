#include <iostream>
#include <cmath>

using namespace std;

int n;
int wine[10001];
int dp[10001][3];


int m(int a,int b, int c)
{
    a=max(a,b);
    a=max(a,c);
    return a;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>wine[i];
    for(int j=1;j<=n;j++)
    {
        dp[j][0]=m(dp[j-1][0],dp[j-1][1],dp[j-1][2]);
        dp[j][1]=dp[j-1][0]+wine[j];
        dp[j][2]=dp[j-1][1]+wine[j];
    }
    cout<<m(dp[n][0],dp[n][1],dp[n][2]);
    return 0;
}