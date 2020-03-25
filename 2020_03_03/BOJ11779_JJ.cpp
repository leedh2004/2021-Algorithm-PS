#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>

using namespace std;


int dis[1001];
vector<pair<int,int>> adj[1001];
vector<pair<int,int>> reverse_adj[1001];
int n,m,s_ct,e_ct;

void solv()
{
    dis[s_ct]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,s_ct});
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dis[here]<cost) continue;

        for(int i=0;i<adj[here].size();i++)
        {
            int next_cost = cost+adj[here][i].second;
            int next_here = adj[here][i].first;
            if(dis[next_here]>next_cost)
            {
                dis[next_here]=next_cost;
                pq.push({-next_cost,next_here});
            }
        }
    }
    printf("%d\n",dis[e_ct]);
    
    queue<pair<int,int>> q;
    stack<int> s;
    //cost, node
    q.push({dis[e_ct],e_ct});
    s.push(e_ct);
    while (1)
    {
        int cost = q.front().first;
        int here = q.front().second;
        q.pop();
        for(int i=0;i<reverse_adj[here].size();i++)
        {
            if(cost-reverse_adj[here][i].second==dis[reverse_adj[here][i].first])
            {
                q.push({dis[reverse_adj[here][i].first],reverse_adj[here][i].first});
                s.push(reverse_adj[here][i].first);
                if(reverse_adj[here][i].first==s_ct)
                {
                    printf("%d\n",s.size());
                    while (!s.empty())
                    {
                        printf("%d ",s.top());
                        s.pop();
                    }
                    return ;
                }
                break;
            }
        }
    }
    
   return ;
}

int main()
{
    int s,e,c;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) dis[i]=INT_MAX;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&s,&e,&c);
        adj[s].push_back({e,c});
        reverse_adj[e].push_back({s,c});
    }
    scanf("%d%d",&s_ct,&e_ct);
    solv();
    return 0;
}
