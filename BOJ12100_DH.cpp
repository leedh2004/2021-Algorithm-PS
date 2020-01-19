#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int b[20][20];
int n; // board size
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = {-1, 1, 0, 0};
int moved[20][20];
int ans = 0;

void move(int y, int x, int direction, int flag){ // flag 1 -> 이미 합쳐졌으니 못 합치게함.
    int ny = y + dy[direction];
    int nx = x + dx[direction];
    if(ny >= 0 && nx >= 0 && nx < n && ny < n){
        if(b[ny][nx] == 0) { //빈 공간인 경우 움직인다.
            b[ny][nx] = b[y][x];
            b[y][x] = 0;
            return move(ny, nx, direction, 0);
        }else if(b[ny][nx] == b[y][x] && flag == 0 && !moved[ny][nx]){ //합쳐지는 케이스
            b[ny][nx] = 2 * b[y][x];
            ans = max(ans, b[ny][nx]);
            b[y][x] = 0;
            return move(ny, nx, direction, 1);
        }
    }
    if(flag == 1) moved[y][x] = 1;
    return;
}

void moveAll(int direction){ // direction == 0 북쪽으로 합치기, direction == 1 남쪽으로 합치기
    memset(moved, 0, sizeof(moved));
    if(direction == 3 || direction == 0){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (b[i][j] > 0) move(i, j, direction, 0);
            }
        }
    }
    else{
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if (b[i][j] > 0) move(i, j, direction, 0);
            }
        }
    }
}

void solve(int cur){
    if(cur == 5) return;
    int temp[20][20];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = b[i][j];
        }
    } //원래값 저장

    for(int cnt=0; cnt<4; cnt++){
        moveAll(cnt);
        solve(cur + 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                b[i][j] = temp[i][j];
            }
        } //원래값 돌아옴   
    }
}

int main(){

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> b[i][j];
            ans = max(ans, b[i][j]);
        }
    }
    solve(0);
    cout << ans << endl;
    return 0;
}