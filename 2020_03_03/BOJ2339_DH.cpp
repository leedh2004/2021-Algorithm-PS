#include <iostream>
using namespace std;

int a[20][20];

int available(int sy, int sx, int ey, int ex){
    int cnt[3] = {0,};
    for(int y=sy; y<=ey; y++){
        for(int x=sx; x<=ex; x++){
            cnt[a[y][x]]++;
        }
    }
    if(cnt[2] == 0) return 0;
    if(cnt[2] == 1){
        if(cnt[1] == 0) return 1;
        else return 0;
    }
    if(cnt[1] == 0) return 0;
    return 2; // 모호한 경우
}


int cut(int sy, int sx, int ey, int ex, bool flag){ // flag 0이면 가로로 자르고, 1이면 세로로 자른다
    
    int k = available(sy, sx, ey, ex);
    if(k == 0) return 0;
    if(k == 1) return 1;
    int ret = 0;
    int first, second;

    for(int y=sy; y<=ey; y++){
        for(int x=sx; x<=ex; x++){
            if(a[y][x] == 1){ // flag에 따라 자를 수 있는지 확인한다.
                if(!flag){ // 가로로 자르는 경우
                    bool possible = true;
                    for(int i=sx; i<=ex; i++){
                        if(a[y][i] == 2){
                            possible = false; break;
                        }
                    }
                    if(possible){
                        ret +=  cut(sy, sx, y-1, ex, !flag) *  cut(y+1, sx, ey, ex, !flag);
                    }
                }else{ // 세로로 자르는경우
                    bool possible = true;
                    for(int i=sy; i<=ey; i++){
                        if(a[i][x] == 2){
                            possible = false; break;
                        }
                    }
                    if(possible){
                        ret += cut(sy, sx, ey, x-1, !flag) *  cut(sy, x+1, ey, ex, !flag);
                    }
                }
            }
        }
    }
    return ret;
}

int main(){

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];
    int ans = cut(0, 0, n-1, n-1, 1) + cut(0, 0, n-1, n-1, 0);
    if(ans == 0) cout << -1;
    else cout << ans;
    return 0;
}