#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;
char table[51][51];
vector <pair<int,int> > key_list;
vector<pair<int, pair<int, int> > > edge;
vector <int> p;

int get_p(int x)
{
    return (p[x]==x)?x: p[x]=get_p(p[x]);
}

bool merge(int x, int y)
{
    x= get_p(x);
    y= get_p(y);
    if(x==y) return false;
    p[x]=y;
    return true;
}


bool is_in(int x, int y)
{
    return (0<x && x<=n) && (0<y&&y<=n);
}

void bfs(int idx)
{
    int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    int dist[51][51];
    memset(dist,-1,sizeof(dist));
    dist[key_list[idx].first][key_list[idx].second]=0;
    queue<pair<int ,int> > q;
    q.push(make_pair(key_list[idx].first,key_list[idx].second));
    while (!q.empty())
    {
        int n_x=q.front().first;
        int n_y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int next_x=n_x+dir[i][0];
            int next_y=n_y+dir[i][1];
            if(is_in(next_x,next_y) && dist[next_x][next_y]==-1 && table[next_x][next_y]!='1')
            {
                dist[next_x][next_y]=dist[n_x][n_y]+1;
                q.push(make_pair(next_x,next_y));
            }
        }
    }
    for(int i=idx+1;i<key_list.size();i++)
    {
        if(dist[key_list[i].first][key_list[i].second]!=-1) edge.push_back(make_pair(dist[key_list[i].first][key_list[i].second],make_pair(idx,i)));
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>table[i][j];
            if(table[i][j]=='S' || table[i][j]=='K') key_list.push_back(make_pair(i,j));
        }
    }
    //간선 bfs로 계산 및 오름차순로 정렬
    for(int i=0;i<key_list.size();i++) bfs(i);
    sort(edge.begin(),edge.end());

    //union find parent 설정
    p.resize(key_list.size());
    for(int i=0;i<p.size();i++) p[i]=i;

    //merge
    int edge_count=0;
    int ans=0;
    for(int i=0;i<edge.size();i++)
    {
        if(merge(edge[i].second.first,edge[i].second.second))
        {
            edge_count++;
            ans+=edge[i].first;
            if(edge_count==m) break;
        }
    }
    if(edge_count==m)cout<< ans;
    else cout<< "-1";
    return 0;
}