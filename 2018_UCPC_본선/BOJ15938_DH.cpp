#include <iostream>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, pair<int, int>> p;
typedef long long ll;

const int MOD = 1000000007;
bool visited[401][401][201];
int a[401][401][201];
int obstacle[401][401];
int dy[] = { 1, 0, -1, 0};
int dx[] = { 0, -1, 0, 1};

int main(){
    int sx, sy;
    cin >> sx >> sy;
    int mx = 200 - sx;
    int my = 200 - sy;
    
    sx += mx;
    sy += my; // ( 200, 200 ) 으로 옮김

    int t;
    cin >> t;

    int gx, gy;
    cin >> gx >> gy;

    gx += mx;
    gy += my;
    
    if ( !(gx >= 0 && gy >= 0 && gx <= 400 && gy <= 400) ){
        cout << 0;
        return 0;
    }

    int n;
    cin >> n;

    while(n--){
        int x, y;
        cin >> x >> y;
        x += mx;
        y += my;
        if (x >= 0 && x <= 400 && y >= 0 && y <= 400) obstacle[y][x] = 1; // 장애물 등록
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {sy, sx}});
    a[sy][sx][0] = 1;

    while(!q.empty()){
        int y = q.front().second.first;
        int x = q.front().second.second;
        int k = q.front().first;
        q.pop();
        if(k >= t) break;
        if(y == gy && x == gx) continue;

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx >= 0 && nx <= 400 && ny >= 0 && ny <= 400){
                if(obstacle[ny][nx]) continue;
                if(!visited[ny][nx][k+1]){
                    q.push({k+1,{ny, nx}});
                    visited[ny][nx][k+1] = 1;
                }
                a[ny][nx][k+1] = (a[ny][nx][k+1] + a[y][x][k]) % MOD;
            }
        }
    }

    ll sum = 0;
    for(int i=0; i<=t; i++){
        sum = (sum + a[gy][gx][i]) % MOD;
    }
    cout << sum;
    return 0;
}