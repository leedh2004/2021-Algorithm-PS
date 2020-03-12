#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long int ans=0;
long long int now=0;
long long int n;

vector<long long int> v;

int main()
{
    scanf("%lld",&n);
    v.resize(n);
    for(int i=0;i<n;i++) 
    {
        scanf("%lld",&v[i]);
        v[i]--;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        if(now<=v[i])
        {
            ans=ans+v[i]-now;
            now++;
        }
    }
    cout<<ans;
    return 0;
}