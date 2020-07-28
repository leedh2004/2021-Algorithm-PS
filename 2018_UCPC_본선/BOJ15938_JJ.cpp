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
bool obstacle[401][401];
int dp[401][401][201];
bool visited[401][401][202];
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int mod = 1000000007;

bool is_in(int nx,int ny){
    return (0<=nx && nx < 401 && 0<=ny && ny<401);
}

int get_dis(int x,int y, int nx, int ny){
    return abs(x-nx) + abs(y-ny);
}


void bfs(){
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(200,200),0));
    while (!q.empty())
    {
        pair<int,int> now = q.front().first;
        int dis = q.front().second;
        pair<int,int> next;
        q.pop();
        
        //순서대로 나오기 때문에, t를 넘어가는 distance가 나오면 break한다.
        if(dis>=t) break;

        //이미 도착한 경우 건너뛴다.
        if(now.first == dx && now.second == dy) continue;

        for(int i=0;i<4;i++){
            //이동 좌표
            next.first = now.first + d[i][0];
            next.second = now.second + d[i][1];

            //큐삽입
            if(is_in(next.first,next.second)&& obstacle[next.first][next.second]==0&& get_dis(dx,dy,next.first,next.second)<= (t-dis)) {
                
                if(!visited[next.first][next.second][dis+1]){
                    visited[next.first][next.second][dis+1] = 1;
                    q.push(make_pair(next,dis+1));
                }
                dp[next.first][next.second][dis+1] = (dp[next.first][next.second][dis+1] + dp[now.first][now.second][dis])%mod;
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
    dx = dx - nx + 200;
    dy = dy - ny + 200;

    //장애물 입력
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&tmpx,&tmpy);
        tmpx = tmpx - nx + 200;
        tmpy = tmpy - ny + 200;
        if (is_in(tmpx,tmpy)){
            obstacle[tmpx][tmpy] = 1;
        }
    }

    dp[200][200][0] = 1;
    bfs();
    for(int i=0;i<=t;i++) {
        ans = (ans + dp[dx][dy][i])%mod;
    }
    printf("%lld\n",ans);
    return 0;
}