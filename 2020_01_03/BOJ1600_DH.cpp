#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

struct my {
    int y; int x; int z;
};

queue<my> q; //q.first = y좌표, q.second = x좌표
int b[201][201][31]; //b[y][x][k] = y좌표, x좌표, 말의 움직임을 k번 했을때 최단 이동횟수
                     //b[y][x][k] == -1 이동하지 않은 경우, -2 장애물이 있는 경우
int k, w, h;

int hx[8] = {1, 2, -2, -1, 1, 2, -2, -1}; // 말의 움직임
int hy[8] = {2, 1, 1, 2, -2, -1, -1, -2 }; 
int mx[4] = {1, 0, -1, 0}; // 원숭이의 움직임
int my[4] = {0, 1, 0, -1};

int bfs(){
    q.push({0, 0, 0});
    b[0][0][0] = 0;
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int z = q.front().z;
        int here = b[y][x][z];

        if(y == h-1 && x == w-1)
            return b[y][x][z];

        q.pop();

        if(z < k){
            for(int i=0; i<8; i++){
                int ny = y + hy[i];
                int nx = x + hx[i];
                int nz = z + 1;
                if(ny < h && nx < w && ny >= 0 && nx >=0 ){
                    if( b[ny][nx][nz] == 0 && b[ny][nx][0] != -1) {
                        q.push({ny, nx, nz});
                        b[ny][nx][nz] = here + 1; 
                    }
                }
            }
        }

        for(int i=0; i<4; i++){
            int ny = y + my[i];
            int nx = x + mx[i];
            if(ny < h && nx < w && ny >= 0 && nx >=0){
                if( b[ny][nx][z] == 0 && b[ny][nx][0] != -1) {
                    q.push({ny, nx, z});
                    b[ny][nx][z] = here + 1; 
                }
            }
        }
    }
    return -1;
}

int main(){

    cin >> k >> w >> h;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> b[i][j][0];
            if (b[i][j][0]) b[i][j][0] = -1;
        }
    }
    cout << bfs();

    return 0;
}