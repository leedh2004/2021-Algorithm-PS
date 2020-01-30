#include <iostream>
#include <vector>
using namespace std;

struct shark{
    int s; int d; int z;
};
int R, C, M;

vector<shark> v;
shark b[105][105];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int main(){

    cin >> R >> C >> M;
    shark trash = {0, 0, 0};
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            b[i][j] = trash; // 모든게 0인 값으로 채워준다.

    for(int i=0; i<M; i++){
        int r, c, s, d, z; // (r,c) s=속력 d=이동방향 z=크기
        cin >> r >> c >> s >> d >> z;
        shark zors;
        zors.s = s; zors.d = d - 1; zors.z = z;
        b[r][c] = zors;
    }
    
    int ans = 0;

    for(int cnt=1; cnt<=C; cnt++){ // 낚시왕이 한 칸 씩 움직임
        shark temp[105][105]; //움직인 상어들의 위치
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                temp[i][j] = trash; // 모든게 0인 값으로 채워준다.

        for(int j=1; j<=R; j++){
            if( b[j][cnt].z ){ // 가까운 상어를 잡는다.
                ans += b[j][cnt].z;
                b[j][cnt] = trash;
                break;
            }
        }

        // 상어들의 움직임 구현
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if (b[i][j].z){ // 상어의 존재
                    int r = i; int c = j; int s = b[i][j].s; int d = b[i][j].d; int z = b[i][j].z;
                    while(s >= 0){ //
                        int nr = r + dy[d] * s;
                        int nc = c + dx[d] * s;
                        if(nr <= 0){ // 북쪽 넘어감
                            s -= r - 1;
                            r = 1;
                            d = 1; // 남쪽으로 방향 바꿈.
                        }
                        else if(nr > R){
                            s -= R - r;
                            r = R;
                            d = 0;
                        }
                        else if(nc <= 0){ // 왼쪽 넘어감
                            s -= c - 1;
                            c = 1;
                            d = 2;
                        }
                        else if(nc > C){
                            s -= C - c;
                            c = C;
                            d = 3;
                        }
                        else{ // 정착함.
                            shark movedshark = { b[i][j].s, d, b[i][j].z };
                            //b[i][j] = trash;
                            if (temp[nr][nc].z){
                                if(temp[nr][nc].z < movedshark.z)
                                    temp[nr][nc] = movedshark;
                            }
                            else{
                                temp[nr][nc] = movedshark;
                            }
                            s = -1;
                        }
                    }
                }
            }
        }

        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                b[i][j] = temp[i][j]; // 움직인 값 복사
    }
    cout << ans;
    return 0;
}