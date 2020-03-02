#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int n;
long long int dist[501];
long long int int_max=10000*500;
bool flag=false;
struct edge
{
    int s;
    int e;
    int c;
};
vector<edge> v;

void solv()
{
    for(int i=1;i<=n;i++) dist[i]=int_max;
    dist[1]=0;
    //최소거리 찾기
    for(int i=1;i<n;i++)
    {
       for(int j=0;j<v.size();j++)
       {
           if(dist[v[j].s]==int_max) continue;
           if(dist[v[j].s]+v[j].c<dist[v[j].e]) dist[v[j].e]=dist[v[j].s]+v[j].c;
       }
    }
    //사이클 찾기
    for(int j=0;j<v.size();j++)
    {
        if(dist[v[j].s]==int_max) continue;
        if(dist[v[j].s]+v[j].c<dist[v[j].e]) flag=true;
    }

    //있다면 종료
    if(flag)
    {
        cout<<"-1";
        return ;
    }

    for(int i=2;i<=n;i++) printf("%lld\n",(dist[i]==int_max)?-1:dist[i]);
}

int main()
{
    int m,a,b,c;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        v.push_back({a,b,c});
    }
    solv();
    return 0;
}
