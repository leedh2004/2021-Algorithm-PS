#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

int r,c,t,a_x,a_y;
int v=0;
int arr[2][51][51];
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};



int is_in(int x,int y)
{
    return (0<x&&x<=r)&&(0<y&&y<=c);
}

void dust()
{
    int b,a,x,y;
    b=v;
    a=v?0:1;
    //after table 초기화
    memset(arr[a],0,sizeof(arr[a]));
    //현재 table을 aftertable을 가르키게 해줌
    v=v?0:1;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++) 
        {
            if(arr[b][i][j]==0) continue;
            //과거에 확산되었을 수도 있기 때문에 : 현재 미세먼지값 = 현재 미세먼지값 + 과거 미세먼지값
            arr[a][i][j]=arr[a][i][j]+arr[b][i][j];
            for(int k=0;k<4;k++)
            {
                //tmp=arr[b][i][j];
                x=i+d[k][0];
                y=j+d[k][1];
                if(is_in(x,y)&& !( (x==a_x&&y==a_y) || (x==a_x-1&&y==a_y) ))
                {
                    arr[a][x][y]=arr[a][x][y]+arr[b][i][j]/5;
                    arr[a][i][j]=arr[a][i][j]-arr[b][i][j]/5;
                }
            }
        }
    } 
    //공기청정기 미세먼지 0으로 초기화
    arr[a][a_x-1][a_y]=0;
    arr[a][a_x][a_y]=0;
}


void mashine()
{
    int b,a;
    b=v;
    a=v?0:1;
    v=v?0:1;
    memcpy(arr[a],arr[b],sizeof(arr[a]));

    //행 이동
    for(int j=1;j<c;j++)
    {
        arr[a][a_x-1][j+1]= arr[b][a_x-1][j];
        arr[a][a_x][j+1]= arr[b][a_x][j];
        arr[a][1][c-j]=arr[b][1][c-j+1];
        arr[a][r][c-j]=arr[b][r][c-j+1];
    }
    //위쪽 열 이동
    for(int i=1;i<=a_x-2;i++)
    {
        arr[a][i+1][1]=arr[b][i][1];
        arr[a][a_x-i-1][c]=arr[b][a_x-i][c];
    }
    //아래쪽 열 이동
    for(int i=r;i>a_x;i--)
    {
        arr[a][i-1][1]=arr[b][i][1];
        arr[a][a_x+1+(r-i)][c]=arr[b][a_x+(r-i)][c];
    }
    //공기청정기 미세먼지 0으로 초기화
    arr[a][a_x-1][a_y]=0;
    arr[a][a_x][a_y]=0;
}

int count()
{
    int num=0;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++) 
        {
            if(arr[v][i][j]>0) num=num+arr[v][i][j];
        }
    } 
    return num;
}


int main()
{
    cin>>r>>c>>t;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++) 
        {
            cin>>arr[0][i][j];
            if(arr[0][i][j]==-1)
            {
                a_x=i;
                a_y=j;
            }
        }
    } 
    for(int i=0;i<t;i++)
    {
        dust();
        mashine();
    }
    cout<<count();
    return 0;
}