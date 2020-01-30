#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int b[20][20];
int dist[20][20];

const int INF = 987654321;
int y, x, s = 2; // (y, x) 아기상어 위치, s 아기상어 크기
int ty, tx; // 다음 먹이의 위치
int n;
int time;
struct p { int y; int x; };
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void find_dist(int y, int x){ // 아기 상어의 위치에서 이동최소값
    queue<p> q;
    q.push({y, x});
    dist[y][x] = 0;

    while(!q.empty()){
        int qy = q.front().y; int qx = q.front().x; int qd = dist[qy][qx];
        q.pop();
        for(int i=0; i<4; i++){
            int ny = qy + dy[i]; int nx = qx + dx[i];
            
            if(ny >= 0 && ny < n && nx >= 0 && nx < n && b[ny][nx] <= s && dist[ny][nx] == -1){
                dist[ny][nx] = qd + 1;
                q.push({ny, nx});
            }

        }
    }
}

int solve(){
    int eat = 0;

    while(1){
        memset(dist, -1, sizeof(dist));
        int distance = INF; // 먹이와의 거리를 무한값으로 초기화
        find_dist(y, x);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(b[i][j] == 9 || b[i][j] == s) continue; // 아기 상어의 위치거나 같은 크기라면 넘어간다.
                if(b[i][j] && b[i][j] < s){
                    int d = dist[i][j];
                    if (d < distance && d != -1){
                         distance = d;
                         ty = i; tx = j;
                    }
                }
            }
        }

        if(distance == INF) return time; // 먹을 수 있는 상어가 없다.
        eat++;
        b[y][x] = 0;
        y = ty; x = tx; b[y][x] = 9;
        if(eat == s){
            s = s + 1;
            eat = 0;
        }
        time += distance;
    }
}


int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> b[i][j];
            if(b[i][j] == 9){
                y = i;
                x = j;
            }
        }
    }
    cout << solve();

    return 0;
}