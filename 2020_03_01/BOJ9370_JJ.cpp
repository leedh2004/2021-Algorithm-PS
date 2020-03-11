#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct edge
{
    int ed;
    int cost;
};

int d[3][2001];
int st_point[3];
int T,n,m,t,s,g,h,ghcost;
vector<edge> adj[2001];
vector<int> t_list;

void solv()
{
    int now,next,now_cost,next_cost;
    bool val,next_val;
    priority_queue<pair<int,int> > pq;
    st_point[0]=s;
    st_point[1]=g;
    st_point[2]=h;
    for(int i=0;i<3;i++)
    {
        for(int j=1;j<=n;j++) d[i][j]=INT_MAX;
        d[i][st_point[i]]=0;
        pq.push({0,st_point[i]});
        while(!pq.empty())
        {
            now=pq.top().second;
            now_cost=-pq.top().first;
            pq.pop();
            if( d[i][now] <now_cost ) continue;
            for(int k=0;k<adj[now].size();k++)
            {
                next_cost=now_cost+adj[now][k].cost;
                next=adj[now][k].ed;
                if(d[i][next]>next_cost)
                {
                    d[i][next]=next_cost;
                    pq.push({-next_cost,next});
                }
            }
        }
    }
    sort(t_list.begin(),t_list.end());
    for(int i=0;i<t_list.size();i++)
    {
        if(d[0][t_list[i]]!=INT_MAX)
        {
            if(d[0][t_list[i]] == (d[0][g]+ghcost+d[2][t_list[i]]))printf("%d ",t_list[i]);
            else if (d[0][t_list[i]] == (d[0][h]+ghcost+d[1][t_list[i]])) printf("%d ",t_list[i]);
        }
    }
    printf("\n");
    t_list.clear();
    for(int i=1;i<=n;i++) adj[i].clear();
}

int main()
{
    int start,end,cost;
    bool g_h;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d%d",&n,&m,&t,&s,&g,&h);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&start,&end,&cost);
            if(g==start&&h==end) ghcost=cost;
            else if (h==start&&g==end) ghcost=cost;
            adj[start].push_back({end,cost});
            adj[end].push_back({start,cost});
        }
        while(t--) 
        {
            scanf("%d",&cost); 
            t_list.push_back(cost);
        }
        solv();
    }
}






/*
struct edge
{
    int ed;
    int cost;
    bool gh;
};

struct dist
{
    int d;
    bool gh;
};

int T,n,m,t,s,g,h;
vector<edge> adj[2001];
dist d[2001];
vector<int> t_list;

void solv(int s)
{
    int now,next,now_cost,next_cost;
    bool val,next_val;
    priority_queue<pair<int,pair<int,bool > > > pq;
    for(int i=1;i<=n;i++) d[i]={INT_MAX,false};
    d[s].d=0;
    pq.push({0,{s,false}});
    while(!pq.empty())
    {
        now=pq.top().second.first;
        now_cost=-pq.top().first;
        val=pq.top().second.second;
        pq.pop();
        if( d[now].d <now_cost ) continue;
        for(int i=0;i<adj[now].size();i++)
        {
            next_cost=now_cost+adj[now][i].cost;
            next=adj[now][i].ed;
            next_val= (val||adj[now][i].gh);
            if( d[next].d==next_cost && next_val==true) d[next].gh=true;
            else if(d[next].d>next_cost)
            {
                d[next].d=next_cost;
                d[next].gh=next_val;
                pq.push({-next_cost,{next,next_val}});
            }
        }
    }
    sort(t_list.begin(),t_list.end());
    for(int i=0;i<t_list.size();i++)
    {
        if( d[t_list[i]].gh==true) printf("%d ",t_list[i]);
    }
    printf("\n");
    t_list.clear();
    for(int i=1;i<=n;i++) adj[i].clear();
}

int main()
{
    int start,end,cost;
    bool g_h;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d%d",&n,&m,&t,&s,&g,&h);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&start,&end,&cost);
            if( (start==g&&end==h) ||(start==h)&&(end==g) ) g_h=true;
            else g_h=false;
            adj[start].push_back({end,cost,g_h});
            adj[end].push_back({start,cost,g_h});
        }
        while(t--) 
        {
            scanf("%d",&cost); 
            t_list.push_back(cost);
        }
        solv(s);
    }

}
*/