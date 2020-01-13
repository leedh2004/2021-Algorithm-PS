#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

int N,W,W_X[1001],W_Y[1001];
int start_x,start_y;
int dp[1001][1001];
int which_car[1001];

int dist(int from, int to, int var) 
{
    if(from==0&&var==1) return abs(1-W_X[to])+abs(1-W_Y[to]);
    else if(from==0&&var==2) return abs(N-W_X[to])+abs(N-W_Y[to]);
    else return abs(W_X[from]-W_X[to])+abs(W_Y[from]-W_Y[to]);
}

/*
경찰차1이 i번째 사건, 경찰차2가 j번째 사건에 있을때
dp[i][j] = min(dp[i-1][j]+dist(경찰차1의 위치,사건i의 위치),dp[i][j-1]+dist(경찰차2의 위치,사건j의 위치))
*/

int dp_bottom_up(int i,int j)
{
    if(i == W || j == W) return 0;    
    int& ref = dp[i][j];
    if(ref!=-1) return ref;
    int next=max(i,j)+1;
    int a=dp_bottom_up(next,j)+dist(i,next,1);
    int b=dp_bottom_up(i,next)+dist(j,next,2);
    return ref=min(a,b);
}

void tracking(int i,int j)
{
    if(i == W || j == W) return ;    
    int next=max(i,j)+1;
    int a=dp_bottom_up(next,j)+dist(i,next,1);
    int b=dp_bottom_up(i,next)+dist(j,next,2);
    if(a<b) 
    {
        printf("1\n");
        tracking(next,j);
    }
    else 
    {
        printf("2\n");
        tracking(i,next);
    }   
}


int main()
{
    /*input*/
    cin>>N>>W;
    for(int i=1;i<=W;i++) cin>>W_X[i]>>W_Y[i];
    fill_n(dp[0],1001*1001,-1);
    cout<<dp_bottom_up(0,0)<<"\n";
    tracking(0,0);
    return 0;
}