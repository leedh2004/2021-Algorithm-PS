#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

vector<int> v;

long long int dp[300001];

int main()
{
    int n,q,start,end;
    cin>>n>>q;
    v.resize(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++)
    {
         dp[i]=dp[i-1]+v[i-1];
         //cout<<dp[i]<<"\n";
    }
    
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&start,&end);
        cout<< dp[end]-dp[start-1]<<"\n";
    }
    return 0;
}
