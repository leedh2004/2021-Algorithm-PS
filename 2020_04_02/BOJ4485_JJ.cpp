#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int table[125][125];
int dist[125][125];
int n;
int INF = 987654321;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool is_in(int x,int y)
{
    return 0<=x && x<n && 0<=y && y<n;
}

void dijkstra()
{
    priority_queue <pair <int,pair<int,int> > > pq;
    pq.push(make_pair(-table[0][0],make_pair(0,0)));
    dist[0][0]=0;
    while (!pq.empty())
    {
        int now_cost = -pq.top().first;
        int now_x=pq.top().second.first;
        int now_y=pq.top().second.second;
        pq.pop();
        for(int i=0;i<4;i++)
        {
            int next_x=now_x+dir[i][0];
            int next_y=now_y+dir[i][1];
            if(!is_in(next_x,next_y)) continue;
            int next_cost=now_cost+table[next_x][next_y];
            if(dist[next_x][next_y]>next_cost)
            {
                dist[next_x][next_y]=next_cost;
                pq.push(make_pair(-next_cost,make_pair(next_x,next_y)));
            }
        }
    } 
    return ;
}

int main()
{
    int idx=0;
    while (1)
    {
        scanf("%d",&n);
        if(n==0) break;
        //memset(table,0,sizeof(table));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&table[i][j]);
                dist[i][j]=INF;
            }
        }
        dijkstra();
        printf("Problem %d: %d\n",++idx,dist[n-1][n-1]);
    }
    return 0;
}