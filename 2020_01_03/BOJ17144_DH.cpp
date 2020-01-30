#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int r, c, t;
int b[50][50];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
vector<int> v; // 공기 청정기 y좌표를 받는다.
               // v[0]을 기점으로 위로 회전, v[1]을 기점으로 아래로 회전한다.

void make_dust(){ //하루 후 미세먼지가 생긴 뒤의 좌표
    int temp[50][50];
    memset(temp, 0, sizeof(temp));
    for(int y=0; y<r; y++){
        for(int x=0; x<c; x++){
            if ( b[y][x] > 0 ){
                int t = b[y][x] / 5;
                for(int i=0; i<4; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(ny >= 0 && nx >= 0 && ny < r && nx < c && b[ny][nx] != -1){
                        temp[ny][nx] += t;
                        b[y][x] -= t;
                    }
                }
            }
        }
    }
    for(int y=0; y<r; y++){
        for(int x=0; x<c; x++){
            b[y][x] += temp[y][x];
        }
    }
}

void clean(){
    int y = v[0];
    int y2 = v[1];
    for(int j=y-1; j>=1; j--) b[j][0] = b[j-1][0];
    for(int i=0; i<c-1; i++) b[0][i] = b[0][i+1];
    for(int j=0; j<=y-1; j++) b[j][c-1] = b[j+1][c-1];
    for(int i=c-1; i>=1; i--) b[y][i] = b[y][i-1];
    b[y][1] = 0;
//////////////////////////////////////
    for(int j=v[1]+1; j<r; j++) b[j][0] = b[j+1][0];
    for(int i=1; i<c; i++) b[r-1][i-1] = b[r-1][i];
    for(int j=r-1; j>v[1]; j--) b[j][c-1] = b[j-1][c-1];
    for(int i=c-1; i>=1; i--) b[v[1]][i] = b[v[1]][i-1];
    b[v[1]][1] = 0;
}

void nextDay(int cur){
    if (cur == t){
        int sum = 2;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                sum += b[i][j];
        cout << sum;
        return;
    }
    make_dust();
    clean();
    nextDay(cur + 1);
}

int main(){
    cin >> r >> c >> t;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> b[i][j];
            if (b[i][j] == -1) v.push_back(i);
        }
    }
    nextDay(0);
    return 0;
}