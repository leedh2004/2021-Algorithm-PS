#include <iostream>
#include <cmath>

using namespace std;

int n;
int dp[1001];
int arr[1001];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    dp[1]=arr[1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i]=max(dp[i],dp[i-j]+arr[j]);
        }
        //cout<<"dp i : "<<i<<" value : "<<dp[i]<<"\n";
    }
    cout<<dp[n];
    return 0;
}