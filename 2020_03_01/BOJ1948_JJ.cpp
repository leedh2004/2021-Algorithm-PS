#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

vector<pair<int,int> >adj[10001];
vector<pair<int,int> >re_adj[10001];
int dist[10001];
int indegree[10001];
bool visited[10001][10001];
int n,m,s_city,e_city;

/*
int count(int n_index)
{
    int c=0;
    if(n_index==s_city) return 0;
    else
    {
        for(int i=0;i<re_adj[n_index].size();i++)
        {
            if(dist[n_index]-re_adj[n_index][i].second==dist[re_adj[n_index][i].first]) 
            {
                if(ck[n_index][re_adj[n_index][i].first])
                {
                    c=c+count(re_adj[n_index][i].first);
                }
                else
                {
                    ck[n_index][re_adj[n_index][i].first]=true;
                    c=c+count(re_adj[n_index][i].first)+1;
                }
                
            }
        }
    }
    return c;
}
*/

void t_sort(int st,int ed)
{
    queue<int> q;
    q.push(st);
    int now;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(int i=0;i<adj[now].size();i++)
        {
            indegree[adj[now][i].first]--;
            dist[adj[now][i].first] = max(dist[adj[now][i].first],dist[now]+adj[now][i].second);
            if(indegree[adj[now][i].first]==0) q.push(adj[now][i].first);
        }
    }
    printf("%d\n",dist[ed]);
    int ans=0;
    q.push(ed);
    memset(visited,false,sizeof(visited));
    while (!q.empty())
    {
        now=q.front();
        q.pop();
        for(int i=0;i<re_adj[now].size();i++)
        {
            if(dist[now]-re_adj[now][i].second==dist[re_adj[now][i].first] && !visited[now][re_adj[now][i].first]) 
            {
                ans++;
                visited[now][re_adj[now][i].first]=true;
                q.push(re_adj[now][i].first);
            }
        }
    }
    
    printf("%d",ans);
    //printf("%d",count(ed));
}

int main()
{
    int s,e,c;
    scanf("%d%d",&n,&m);
    while (m--)
    {
        scanf("%d%d%d",&s,&e,&c);
        adj[s].push_back({e,c});
        re_adj[e].push_back({s,c});
        indegree[e]++;
    }
    scanf("%d%d",&s_city,&e_city);
    t_sort(s_city,e_city);
    return 0;
}