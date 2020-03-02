#include <iostream>
#include <queue>
#include <string>
#include <climits>

using namespace std;

int n,p;
int dp[1<<16];
int cost[17][17];
int now=0;
string tmp;

//몇개가 켜져있는가?
int bit_count(int x)
{
    if(x==0) return 0;
    return x%2+bit_count(x/2);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>cost[i][j];
    }
    string tmp;cin>>tmp;tmp=" "+tmp;
    for(int i=1;i<=n;i++) 
    {
        if(tmp[i]=='Y') now=now+1;
        now=now<<1;
    }
    now=now>>1;
    printf("%d\n",now);
    cin>>p;
    //cout<<solve();
    return 0;
}