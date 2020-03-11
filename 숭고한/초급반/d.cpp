#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n,m,sz;
int d[2][2]={{1,0},{0,1}};
int table[301][301];
bool ck[301][301];

bool is_in(int x,int y)
{
    return (0<x&&x<=n)&&(0<y&&y<=m);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)scanf("%d",&table[i][j]);
    }
    memset(ck,false,sizeof(ck));
    queue<pair<int,int>> q;
    q.push({1,1});
    ck[1][1]=true;
    int x,y,ans=1;
    int next_x,next_y;
    while (!q.empty())
    {
        sz=q.size();
        for(int i=1;i<=sz;i++)
        {
            x=q.front().first;
            y=q.front().second;
            q.pop();
            for(int j=1;j<=table[x][y];j++)
            {
                for(int k=0;k<2;k++)
                {
                    next_x=x+j*d[k][0];
                    next_y=y+j*d[k][1];
                    if(is_in( next_x,next_y) && (!ck[next_x][next_y]))
                    {
                        if(next_x==n && next_y==m)
                        {
                            cout<<ans;
                            return 0;
                        }
                        q.push({next_x,next_y});
                        ck[next_x][next_y]=true;
                    }
                }
             }
        }
        ans++;
    }
    return 0;
}