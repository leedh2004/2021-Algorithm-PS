#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

long long int ans=0;

int dp[1001];

int main()
{
    cin>>n;
    //max_bar=n/2;
    //for(int i=0;i<=max_bar;i++) cal_number_of_way(i);
    dp[1]=1;
    dp[2]=3;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-2];
        dp[i]=dp[i]%10007;
    }
    cout<<dp[n];
    return 0;
}