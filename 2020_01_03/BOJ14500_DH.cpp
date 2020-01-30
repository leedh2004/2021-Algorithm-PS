#include <iostream>
#include <algorithm>
using namespace std;


int b[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[500][500];
int n, m;
int ans;
int k[4][4][2] = {
     { {0, 0}, {0, 1}, {0, 2}, {-1, 1} },
     { {0, 0}, {0, 1}, {0, 2}, {1, 1} },
     { {0, 0}, {-1, 0}, {0, 1}, {1, 0} },
     { {0, 0}, {0, 1}, {-1, 1}, {1, 1} }
};

void tetrino(int cur, int y, int x, int sum){
    if(cur == 3){
        ans = max(ans, sum);
        return;
    }
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && nx >= 0 && ny < n && nx < m && !visited[ny][nx]){
            tetrino(cur+1, ny, nx, sum + b[ny][nx]);
        }
    }
    visited[y][x] = 0;
    return;
}

void myfunc(int y, int x){ // ㅗ 모양만 따로 처리해준다
    for(int i=0; i<4; i++){
        int ret = 0;
        for(int j=0; j<4; j++){
            int ny = y + k[i][j][0];
            int nx = x + k[i][j][1];
            if(ny >= 0 && nx >= 0 && ny < n && nx < m)
                ret += b[ny][nx];
        }
        ans = max(ans, ret);
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> b[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tetrino(0, i, j, b[i][j]);
            myfunc(i, j);
        }
    }
    cout << ans;
    return 0;
}