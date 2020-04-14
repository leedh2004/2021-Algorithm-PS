#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int dist[50001];
vector<int> adj[50001];
int n,m;
int INF=987654321;

void dijkstra()
{
    priority_queue <pair<int,int>  > pq;
    pq.push(make_pair(0,1));
    dist[1]=0;
    while (!pq.empty())
    {
        int now_cost = -pq.top().first;
        int now_city=pq.top().second;
        pq.pop();
        if(dist[now_city] < now_cost) continue;
        for(int i=0;i<adj[now_city].size();i++)
        {
            int next_city = adj[now_city][i];
            if(dist[next_city]>now_cost+1)
            {
                dist[next_city]=now_cost+1;
                pq.push(make_pair(-(now_cost+1),next_city));
            }
        }
    } 
    return ;
}
void count()
{
    int max_dist = 0;
    int how_many = 0;
    int idx =0;
    for(int i=1;i<=n;i++)
    {
        if(max_dist<dist[i])
        {
            how_many=1;
            idx=i;
            max_dist=dist[i];
        }
        else if(max_dist==dist[i]) how_many++;
    }
    printf("%d %d %d\n",idx,max_dist,how_many);
    return ;
}

int main()
{
    int st,ed;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)dist[i]=INF;
    while (m--)
    {
        scanf("%d%d",&st,&ed);
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    dijkstra();
    count();
    return 0;
}
