#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int ll;

ll n,m,total;
vector<ll> v;

int main()
{
    ll tmp;
    scanf("%lld%lld",&n,&m);
    v.resize(n);
    for(int i=0;i<n;i++) 
    {
        scanf("%lld",&v[i]);
        v[i]=-v[i];
    }
    sort(v.begin(),v.end());
    v.push_back(0);
    //i+1이 해당 구역의 나무의 수
    ll num_of_tree;
    ll now_h;

    for(int i=1;i<=n;i++)
    {
        ll period = v[i] - v[i-1];
        total = total + i*period;
        //printf("%lld\n",total);
        if(total>=m)
        {
            num_of_tree=i;
            now_h= -v[i];
            break;
        }
    }
    printf("%lld\n",now_h + (total-m)/num_of_tree);
    return 0;
}