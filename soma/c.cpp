#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k,ans;
vector<int> v;
vector<int> vv;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	ans=0;
    v.resize(n);
    vv.resize(n-1);
    for(int i=0;i<n;i++) cin>>v[i];
    ans=v[n-1]-v[0];
    for(int i=0;i<n-1;i++) vv[i]=v[i]-v[i+1];
    sort(vv.begin(),vv.end());
    for(int i=0;i<k-1;i++) ans=ans+vv[i];
    cout<<ans;
    return 0;
}