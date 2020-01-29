#include <iostream>
#include <cmath>

using namespace std;

int n;
int cost=0;
pair<int,int> p[16];
int f_day[16];
int ck[16]={0};

int dp[16]={0}; // dp[i] i번째날에서 cost의 최대값

void dpdp()
{
    for(int i=1;i<=n;i++)
    {
        if(f_day[i]==1) dp[1] = max(dp[0],p[i].second);
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            for(int k=j+1;k<=i;k++)
            {
                if(f_day[k]<=i)
                {
                    dp[i]=max(dp[i],dp[j]+p[k].second);
                }
                dp[i]=max(dp[i],dp[i-1]);
            }
        }
        //cout<<dp[i]<<" \n";
    }
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    for(int i=1;i<=n;i++) f_day[i]=i+p[i].first-1;
    dpdp();
    cout<<dp[n];
    return 0;
}