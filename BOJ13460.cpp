#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
// 은둔고수 크루 미안해 더럽게 풀었어
// bfs 문제 
char board[10][10];
int memo[10][10][10][10]; // rx, ry, bx, by
int n, m;
int gy, gx; // 목표지점

struct my{
    int rx, ry; // 빨강 공의 위치
    int bx, by; // 파란 공의 위치
    int cnt;  // 최소 이동횟수
};

bool operator == (my a, my b){
    return (a.rx == b.rx) && (a.ry == b.ry) && (a.bx == b.bx)&& (a.by == b.by);
};

queue<my> q;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void move(my info, int direction){ // direction 0 아래쪽, 1 위쪽, 2 오른쪽, 3 왼쪽
    int temp[10][10];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == '#') temp[i][j] = 1;
            else temp[i][j] = 0;
        }
    }
    
    temp[info.ry][info.rx] = 2; // 빨간 공
    temp[info.by][info.bx] = 3; // 파란 공

    my before = info; // 이전 정보를 저장해서 움직임이 있는지 비교한다.
    
    while(1){
        int rx = info.rx + dx[direction];
        int ry = info.ry + dy[direction];
        int bx = info.bx + dx[direction];
        int by = info.by + dy[direction];
        
        if(bx >= 0 && bx < m && by >= 0 && by < n) {
            if(by == gy && bx == gx) return;
            if(temp[by][bx] == 0){
                temp[info.by][info.bx] = 0;
                info.bx = bx;
                info.by = by;
                temp[info.by][info.bx] = 3;
            }
        }

        if(!(info.ry == gy && info.rx == gx)){
            if(rx >= 0 && rx < m && ry >= 0 && ry < n) {
                if(temp[ry][rx] == 0){
                    temp[info.ry][info.rx] = 0;
                    info.rx += dx[direction];
                    info.ry += dy[direction];
                    temp[info.ry][info.rx] = 2;
                }
                if(rx == gx && ry == gy) {
                    temp[info.ry][info.rx] = 0;
                    info.ry = gy; info.rx = gx;           
                }  
            }
        }
        if(before == info) break;
        else before = info;
    }

    if (memo[info.rx][info.ry][info.bx][info.by] == -1) {
        memo[info.rx][info.ry][info.bx][info.by] = info.cnt + 1;
        info.cnt+=1;
        q.push(info);
    }
}

void bfs(){

    while(!q.empty()){
        my front = q.front();
        q.pop();
        if(front.ry == gy && front.rx == gx){
            if(front.cnt > 10) cout << -1;
            else cout << front.cnt;
            return;
        }
        for(int i=0; i<4; i++) move(front, i);
    }
    cout << -1;
    return;

}


int main(){

    cin >> n >> m;
    int rx, ry, bx, by;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'R'){
                ry = i; rx = j;
            }
            if(board[i][j] == 'B'){
                by = i; bx = j;
            }
            if(board[i][j] == 'O'){
                gy = i; gx = j;
            }
        }
    }
    memset(memo, -1, sizeof(memo));
    q.push({rx, ry, bx, by, 0});
    memo[rx][ry][bx][by] = 0;
    bfs();
    return 0;
}