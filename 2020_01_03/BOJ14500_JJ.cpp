#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int n,m,most_big_value,q_size;
int check[501][501];
int table[501][501];
int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

struct p
{
    int x;
    int y;
    int b_x;
    int b_y;
    int sum={0};
};

queue <p> q;
p tmp;
int a,b;

int is_out_side(int x, int y)
{
    if((0<x&&x<=n)&&(0<y&&y<=m)) return 0;
    else return 1;
}

int bfs(int x,int y)
{
    int max_sum=0;
    q.push({x,y,x,y,table[x][y]});
    //cout<<"start bfs "<<x<<" "<<y<<"\n";
    for(int i=0;i<4;i++)
    {
        q_size=q.size();
        //cout<<"------------\n";
        for(int j=0;j<q_size;j++)
        {
            tmp=q.front();
            q.pop();
            if(i==3) {
                max_sum=max(max_sum,tmp.sum);
                continue;
            }
            for(int k=0;k<4;k++)
            {
                a=tmp.x+d[k][0];
                b=tmp.y+d[k][1];
                if((!is_out_side(a,b))&&check[a][b]==0&&(!(a==tmp.b_x&&b==tmp.b_y)))
                {
                    //cout<<a<<" "<<b<<"\n";
                    q.push({a,b,tmp.x,tmp.y,tmp.sum+table[a][b]});
                }
            }
        }
    }
    return max_sum;
}


int main()
{
    memset(check,0,sizeof(check));
    memset(table,0,sizeof(table));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>table[i][j];
    }
    //bfs로 만들수있는 도형
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) 
        {
            most_big_value=max(most_big_value,bfs(i,j));
            //check[i][j]=1;
        }
    }
    //ㅏ,ㅓ 확인
    for(int i=2;i<=n-1;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!is_out_side(i,j+1)) most_big_value=max(most_big_value,table[i-1][j]+table[i][j]+table[i+1][j]+table[i][j+1]);
            if(!is_out_side(i,j-1)) most_big_value=max(most_big_value,table[i-1][j]+table[i][j]+table[i+1][j]+table[i][j-1]);
        }
    }
    //ㅗ,ㅜ 확인
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=m-1;j++)
        {
            if(!is_out_side(i+1,j)) most_big_value=max(most_big_value,table[i][j-1]+table[i][j]+table[i][j+1]+table[i+1][j]);
            if(!is_out_side(i-1,j)) most_big_value=max(most_big_value,table[i][j-1]+table[i][j]+table[i][j+1]+table[i-1][j]);
        }
    }
    cout<<most_big_value;
    return 0;
}