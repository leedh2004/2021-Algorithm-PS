#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct edge
{
    int next;
    int cost;
};
vector<edge> v[801];
int n,E,s,e,c;
int arr[3]={1,0,0};
int dist[3][801];
int INT_MAX=3*800*1000+1;

void solv()
{
    int here,there,here_cost,there_cost;
    for(int k=0;k<3;k++)
    {
        dist[k][arr[k]]=0;
        priority_queue<pair<int,int>> pq;
        pq.push({0,arr[k]});
        while(!pq.empty())
        {
            here_cost=-pq.top().first;
            here=pq.top().second;
            pq.pop();
            if(dist[k][here]<here_cost) continue;
            for(int i=0;i<v[here].size();i++)
            {
                there=v[here][i].next;
                there_cost=here_cost+v[here][i].cost;
                if(dist[k][there]>there_cost)
                {
                    dist[k][there]=there_cost;
                    pq.push({-there_cost,there});
                }
            } 
        }
    }
}

int main()
{   
    scanf("%d%d",&n,&E);
    while(E--)
    {
        scanf("%d%d%d",&s,&e,&c);
        v[s].push_back({e,c});
        v[e].push_back({s,c});
    }
    scanf("%d%d",arr+1,arr+2);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<801;j++) dist[i][j]=3*800*1000+1;
    }
    //fill(&dist[0][0],&dist[2][800],3*800*1000+1);
    solv();
    int ans = min(dist[0][arr[1]]+dist[1][arr[2]]+dist[2][n],dist[0][arr[2]]+dist[2][arr[1]]+dist[1][n]);
    printf("%d\n",(ans>=3*800*1000+1)?-1:ans);
    return 0;
}


/*

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
            cost = -pq.top().first;
            here = pq.top().second;
            pq.pop();
            if(dist[i][here]<cost) continue;
            //cout<<arr[i]<<"->"<<now<<" : "<<cost<<" vs "<<dist[i][now]<<"""\n";
            for(int j=0; j < adj[here].size() ;j++)
            {
                there=adj[here][j].first;
                nextDist= cost + adj[here][j].second;
                if(dist[i][there]>nextDist);
                {
                    printf("now:%d cost:%d next:%d now->next:%d before:%d after:%d\n",here,cost,there,dist[i][there,nextDist],adj[here][j].second);
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
    //거리배열 초기화
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
    if(ans>=INT_MAX) cout<<"-1";
    else cout<<ans;
    return 0;
}
*/