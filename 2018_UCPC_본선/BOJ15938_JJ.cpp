#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>

using namespace std;

typedef long long int ll;

int t,n,dx,dy;
ll ans = 0;
bool obstacle[402][402];
ll dp[402][402][200];
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int mod = 1000000009;

bool is_in(int nx,int ny){
    return (0<=nx && nx < 401 && 0<=ny && ny<401);
}

int get_dis(int x,int y, int nx, int ny){
    return abs(x-nx) + abs(y-ny);
}


void bfs(){
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(201,201),0));
    while (!q.empty())
    {
        pair<int,int> now = q.front().first;
        int dis = q.front().second;
        pair<int,int> next;
        q.pop();

        if(dis>t) continue;

        bool flag = false;
        if(dp[now.first][now.second][dis]==0) flag =true;
        for(int i=0;i<4;i++){
            //이동 좌표
            next.first = now.first + d[i][0];
            next.second = now.second + d[i][1];

            //값대입
            if(dis!=0 && flag)  dp[now.first][now.second][dis] =  (dp[now.first][now.second][dis] + dp[next.first][next.second][dis-1])%mod;

            //큐삽입
            if(is_in(next.first,next.second) && obstacle[next.first][next.second]==0) {
                if(get_dis(dx,dy,next.first,next.second)<= (t-dis)) q.push(make_pair(next,dis+1));
            }
        }
        //printf("dp[%d][%d][%d] : %lld \n", now.first,now.second,dis,dp[now.first][now.second][dis]);
    }
}


//T의 범위는 200이다. 따라서 최대 도달가능 거리는 200이다.
bool check(int nx,int ny,int x,int y){
    if (abs(nx-x) + abs(ny-y) <= 200) return true;
    else return false;
}


int main(){
    int nx,ny,tmpx,tmpy;

    //현재좌표
    scanf("%d%d",&nx,&ny);

    //버틸수 있는 시간
    scanf("%d",&t);

    //도착 장소
    scanf("%d%d",&dx,&dy);
    dx = dx - nx + 201;
    dy = dy - ny + 201;

    //장애물 입력
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&tmpx,&tmpy);
        if (check(nx,ny,tmpx,tmpy)){
            //원점 이동 200,200이 항상 시작위치
            obstacle[tmpx-nx+201][tmpy-ny+201] = 1;
        }
    }
    dp[201][201][0] = 1;
    bfs();
    for(int i=0;i<=t;i++) {
        ans = (ans + dp[dx][dy][i])%mod;
    }
    printf("%lld\n",ans);
    return 0;
}