#include <iostream>

using namespace std;
int b[105][105];
int cd[10001];
int n, k, l;

int dx[4] = {0, 1, 0, -1}; // 위쪽, 오른쪽, 아래쪽, 왼쪽
int dy[4] = {-1, 0, 1, 0};
int direction = 1; // direction은 뱀이 향하는 방향
int hy, hx; // heady headx, 뱀의 머리 좌표 (b[hy][hx] = 가장 큰 값)
int ty, tx; // taily tailx, 뱀의 꼬리 좌표 (b[ty][tx] = 가장 작은 값)
int time;

void move(){

    while(1){

        if (cd[time] == 1) { // 시간에 따른 방향전환
            direction += cd[time];
            if(direction == 4) direction = 0;
        }else if(cd[time] == -1){
            direction += cd[time];
            if(direction == -1) direction = 3;
        }

        time++;
        int ny = hy + dy[direction];
        int nx = hx + dx[direction];

        if(ny > n || nx > n || ny < 1 || nx < 1 || b[ny][nx] > 0) { // 종료조건
            cout << time;
            exit(0);
        }
        
        if (b[ny][nx] != -2){ // 사과를 먹지 않은 경우, 꼬리를 움직여줌
            b[ny][nx] = b[hy][hx] + 1;
            b[ty][tx] = 0;

            int temp = 987654321;
            int my = ty, mx = tx;

            for(int j=0; j<4; j++){ // 새로운 꼬리의 좌표를 구해준다.
                int nty = ty + dy[j];
                int ntx = tx + dx[j];

                if( nty <= n  && ntx <= n && nty >= 1 && ntx >= 1 && b[nty][ntx] > 0 && temp > b[nty][ntx] ){
                    temp = b[nty][ntx];
                    my = nty; mx = ntx;
                }

            }

            ty = my; tx = mx;
        }else{ // 사과를 먹은경우, 머리만 이동해준다.
            b[ny][nx] = b[hy][hx] + 1;
        }
        hy = ny; hx = nx; // 뱀의 머리좌표 변경
    }
}

int main(){

    cin >> n >> k;
    for(int i=0; i<k; i++){
        int y, x;
        cin >> y >> x;
        b[y][x] = -2; // 사과 값은 -2
    }
    cin >> l;

    hy = hx = ty = tx = 1;
    b[hy][hx] = 1; // 
    
    for(int i=0; i<l; i++){
        int m;
        char d;
        cin >> m >> d;
        if (d == 'L') cd[m] = -1;
        else if(d == 'D') cd[m] = 1;
    }
    move();

    return 0;
}