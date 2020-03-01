#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

long long int dist[3][801];
vector<pair<int,int> > adj[801];
int n,e,f,s;
long long int ans;
int INT_MAX=999999999;
int arr[3];

void solv()
{
    long long int here,cost,nextDist,there;
    for(int i=0;i<3;i++)
    {
        priority_queue<pair<int,int> > pq;
        dist[i][arr[i]]=0;
        pq.push({0,arr[i]});
        while(!pq.empty())
        {
            //현재 cost가 가장 낮은 노드 선별
            cost=-pq.top().first;
            here=pq.top().second;
            pq.pop();
            if(dist[i][here]<cost) continue;
            for(int j=0;j<adj[here].size();j++)
            {
                there=adj[here][j].first;
                nextDist= cost + adj[here][j].second;
                if(dist[i][there]>nextDist);
                {
                    dist[i][there]=nextDist;
                    pq.push({-nextDist,there});
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&e);
    //memset(adj,-1,sizeof(adj));
    fill(&dist[0][0],&dist[2][800],99999999);
    for(int i=1;i<=e;i++)
    {
        int tmp_s,tmp_e,c;
        scanf("%d%d%d",&tmp_s,&tmp_e,&c);
        adj[tmp_s].push_back({tmp_e,c});
        adj[tmp_e].push_back({tmp_s,c});
        //cout<<tmp_s<<adj[tmp_s][adj[tmp_s].size()-1].first<<adj[tmp_s][adj[tmp_s].size()-1].second<<"\n";
    }
    arr[0]=1;
    scanf("%d%d",&arr[1],&arr[2]);
    solv();
    ans = min(dist[0][arr[1]]+dist[1][arr[2]]+dist[2][n],dist[0][arr[2]]+dist[2][arr[1]]+dist[1][n]);
    if(ans>INT_MAX) cout<<"-1";
    else cout<<ans;
    return 0;
}