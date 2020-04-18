#include <iostream>
using namespace std;

char b[51][51];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> b[i][j];
        }
    }
    int ans = 1;
    for(int len=1; len<=50; len++){
        for(int y=0; y<n; y++){
            for(int x=0; x<m; x++){
                int rx = x + len;
                int dy = y + len;
                if(rx >= m || dy >= n) continue;
                if(b[y][x] == b[dy][x] && b[y][x] == b[dy][rx] && b[y][x] == b[y][rx]) ans = (len+1)*(len+1);
            }
        }
    }
    cout << ans;
    return 0;
}