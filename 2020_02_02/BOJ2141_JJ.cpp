#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long int,long long int> > v;
int n;
long long int town,people;
long long int cost=0;
long long int total_peple=0;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&town,&people);
        total_peple=total_peple+people;
        v.push_back({town,people});
    }
    sort(v.begin(),v.end());
    long long int left=0;
    long long int right=total_peple;
    for(int i=0;i<n;i++)
    {
        left=left+v[i].second;
        right=right-v[i].second;
        if(right<=left) 
        {
            printf("%lld",v[i].first);
            return 0;
        }
    }
    return 0;
}