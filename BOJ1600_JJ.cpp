#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int k,w,h,s;
int arr[201][201];
int ck[201][201][31];

struct p{
    int x;
    int y;
    int nk;
};

p tmp;

queue<p> q;

int d_n[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int d_h[8][2]={{2,1},{1,2},{-1,2},{-2,1},{1,-2},{2,-1},{-2,-1},{-1,-2}};

int is_in(int x,int y)
{
    return (0<x&&x<=h)&&(0<y&&y<=w);
}

int bfs()
{
    q.push({1,1,0});
    ck[1][1][0]=1;
    int x,y;
    int m_n=0;
    while(!q.empty())
    {
        s=q.size();
        m_n++;
        for(int i=0;i<s;i++)
        {
            tmp=q.front();
            //cout<<tmp.x<<" "<<tmp.y<<"\n";
            q.pop();
            for(int j=0;j<4;j++)
            {
                x=tmp.x+d_n[j][0];
                y=tmp.y+d_n[j][1];
                if(is_in(x,y)&&arr[x][y]==0&&ck[x][y][tmp.nk]==-1)
                {
                    if(x==h&&y==w) return m_n;
                    q.push({x,y,tmp.nk});
                    ck[x][y][tmp.nk]=1;
                }
            }
            for(int j=0;j<8;j++)
            {
                x=tmp.x+d_h[j][0];
                y=tmp.y+d_h[j][1];
                if(is_in(x,y)&&arr[x][y]==0&&ck[x][y][tmp.nk+1]==-1&&tmp.nk+1<=k)
                {
                    if(x==h&&y==w) return m_n;
                    q.push({x,y,tmp.nk+1});
                    ck[x][y][tmp.nk+1]=1;
                }
            }
        }
    }


    return -1;
}


int main()
{
    cin>>k>>w>>h;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++) cin>>arr[i][j];
    }
    memset(ck,-1,sizeof(ck));
    cout<<bfs();
    return 0;
}