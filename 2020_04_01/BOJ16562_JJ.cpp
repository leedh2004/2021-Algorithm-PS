#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

//0은 이준석
int disjoint_set[10001];
int n,m,k,tmp,tmp2;
int total_cost=0;
vector<pair<int,int> > cost;

int find(int x)
{
    if(disjoint_set[x]==x) return x;
    else return disjoint_set[x]=find(disjoint_set[x]);
}

bool merge(int x,int y)
{
    int x_m = find(x);
    int y_m = find(y);
    if(x_m==y_m) return false;
    disjoint_set[x_m]=y_m;
    return true;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    cost.resize(n);
    for(int i=1;i<=n;i++)
    {
        disjoint_set[i]=i;
        scanf("%d",&tmp);
        cost[i-1]= make_pair(tmp,i);
    }
    sort(cost.begin(),cost.end());
    while (m--)
    {
        scanf("%d %d",&tmp,&tmp2);
        merge(tmp,tmp2);
    }
    for(int i=0;i<n;i++)
    {
        if(merge(cost[i].second,0))
        {
            total_cost=total_cost+cost[i].first;
            if(total_cost>k)
            {
                printf("Oh no\n");
                return 0;
            }
        }
    }
    printf("%d\n",total_cost);
    return 0;
}