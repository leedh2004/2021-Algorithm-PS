#include <iostream>
#include <cstdio>

using namespace std;

int n,m,d;
int size=0;
int arr[51][51];
pair <int,int> now;


int four_d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int is_in(int x,int y) 
{
    int t=(((0<x)&&(x<=n))&&((0<y)&&(y<=m)));
    return t;
}
int main()
{
    cin>>n>>m>>now.first>>now.second>>d;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>arr[i][j];
    }

    while(1)
    {
        if(arr[now.first][now.second]==0) 
        {
            arr[now.first][now.second]==-1;
            size++;
        }
        int tmp=0;
        for(int i=1;i<=4;i++)
        {
            int next=(d+i)%4;
            if(is_in(now.first+four_d[next][0],now.second+four_d[next][1]) && arr[now.first+four_d[next][0]][now.second+four_d[next][1]]==0)
            {
                d=next;
                now.first=now.first+four_d[next][0];
                now.second=now.second+four_d[next][1];
                tmp++;
                break;
            }
        }
        if(tmp>0) continue;
        int back=(d+2)%4;
        if(is_in(now.first+four_d[back][0],now.first+four_d[back][1]),arr[now.first+four_d[back][0]][now.first+four_d[back][1]]!=1)
        {
            now.first=now.first+four_d[back][0];
            now.second=now.second+four_d[back][1];
            continue;
        }
        if(arr[now.first+four_d[back][0]][now.first+four_d[back][1]]==1) break; 
    }
    cout<<size;
    return 0;
}