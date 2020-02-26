#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

vector<pair<int,pair<int,int> > > edges;
vector<pair<int,int> > node;

int w=1,h=1;
char table[21][21];
int node_index[20][20];
int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int p[10];

bool is_in(int x,int y)
{
    return ((-1<x&&x<h)&&(-1<y&&y<w));
}

void make_edge()
{
    int nx,ny,tmpx,tmpy;
    queue<pair<int,int>> q;
    bool check[20][20];
    for(int i=0;i<node.size();i++)
    {
        int dis=0;
        while(!q.empty()) q.pop();
        memset(check,false,sizeof(check));
        q.push({node[i].first,node[i].second});
        while(!q.empty())
        {
            int sz = q.size();
            dis++;
            for(int j=0;j<sz;j++)
            {
                nx = q.front().first;
                ny = q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    tmpx=nx+d[k][0];
                    tmpy=ny+d[k][1];
                    if(is_in(tmpx,tmpy)&&(!check[tmpx][tmpy])&&(table[tmpx][tmpy]!='x'))
                    {
                        q.push({tmpx,tmpy});
                        check[tmpx][tmpy]=true;
                        if( (table[tmpx][tmpy]=='*'||table[tmpx][tmpy]=='o')&& i!=node_index[tmpx][tmpy])
                        {
                            edges.push_back({dis, {i,node_index[tmpx][tmpy]} });
                        }
                        
                    }
                }
            }
        }
    }
}

int get_paret(int x)
{
    if(p[x]==x) return x;
    return p[x]=get_paret(p[x]);
}

bool merge(int x,int y)
{
    x=get_paret(x);
    y=get_paret(y);
    if(x!=y) 
    {
        p[x]=y;
        return true;
    }
    return false;
}

int main()
{
    while(1)
    {
        cin>>w>>h;
        if(w==0 && h==0) break;
        memset(node_index,-1,sizeof(node_index));
        node.clear();
        edges.clear();
        for(int i=0;i<h;i++) 
        {
            cin>>table[i];
            for(int j=0;j<w;j++)
            {
                if(table[i][j]=='*'||table[i][j]=='o') 
                {
                    node.push_back({i,j});
                    node_index[i][j]=node.size()-1;
                }
            }
        }
        make_edge();
        sort(edges.begin(),edges.end());
        for(int j=0;j<edges.size();j++) cout<<edges[j].second.first<<"-->"<< edges[j].second.second<<" : "<<edges[j].first<<"\n";
        for(int i=0;i<node.size();i++) p[i]=i;
        int ans=0,n_edge=0;
        for(int j=0;j<edges.size();j++)
        {
            if(merge(edges[j].second.first,edges[j].second.second)==true)
            {
                ans=ans+edges[j].first;
                n_edge++;
                if(n_edge==(node.size()-1)) break;
            }
        }
        if(n_edge==(node.size()-1))
        {
            cout<<ans<<"\n";
        }
        else cout<<"-1"<<"\n";
    }
    return 0;
}