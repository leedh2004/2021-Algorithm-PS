#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int w,h;
int n;
int d[8][2]={{-1,-1},{1,-1},{-1,1},{1,1},{1,0},{-1,0},{0,1},{0,-1}};
int arr[51][51];
int ck[51][51];
int x,y;

queue<pair<int,int> > q;

int in(int i,int j)
{
    return (0<i&&i<=h)&&(0<j&&j<=w);
}

void bfs(int i,int j)
{
    q.push({i,j});
    ck[i][j]=1;
    pair <int,int> tmp;
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        for(int k=0;k<8;k++)
        {
            x=tmp.first+d[k][0];
            y=tmp.second+d[k][1];
            if(in(x,y)&&(ck[x][y]==-1)&&arr[x][y])
            {
                q.push({x,y});
                ck[x][y]=1;
            }
        }
    }

}

int main()
{
    while(1)
    {
        cin>>w>>h;
        if((w==0)&&(h==0)) break;
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++) 
            {
                cin>>arr[i][j];
                //cout<<arr[i][j];
            }
        }
        memset(ck,-1,sizeof(ck));
        n=0;
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(ck[i][j]==-1&&arr[i][j]==1)
                {
                    bfs(i,j);
                    n++;
                }
            }
        }
        cout<<n<<"\n";
    }
    return 0;
}

