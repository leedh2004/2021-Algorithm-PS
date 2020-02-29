#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int n;
int arr[5001];
int dp[5001][5001];

int solv(int left, int right, int ans)
{
    if(left>=right) return ans;
    if(dp[left][right]==-1)
    {
        if(arr[left]!=arr[right])
        {
            ans=ans+min(solv(left+1,right,ans),solv(left,right-1,ans))+1;
            dp[left][right]=ans;
            return ans;
        }
        else
        {
            ans=ans+solv(left+1,right-1,ans);
            dp[left][right]=ans;
            return ans;
        }
    }
    return dp[left][right];
}

int main()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++) cin>>arr[i];
    cout<<solv(1,n,0);
}