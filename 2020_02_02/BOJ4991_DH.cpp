#include <iostream>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

int dy[4] = {0, 1, -1, 0};
int dx[4] = {1, 0, 0, -1};

int b[20][20];
int dp[(1 << 11) - 1][20][20]; // dp[ 방문한 더러운 방 비트 마스크] 좌표..
map<pair<int, int>, int> m; // 

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(1){
        memset(dp, 0, sizeof(dp));
        memset(b, 0, sizeof(b));
        int w, h;
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        int idx = 1;
        int y, x;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                char temp;
                cin >> temp;
                if(temp == 'o') y = i, x = j;
                if(temp == 'x') b[i][j] = -1; // 가구는 -1 
                if(temp == '*') b[i][j] = idx++; // 더러운방 Index를 부여한다.
            }
        }
        
        queue<pair<int, pair<int, int> > > q; // bitmask, y, x
        q.push({0, {y, x}}); // queue에 초기위치를 넣어준다. 아무곳도 방문하지 않았으니 bitmask = 0
        
        while(!q.empty()){
            int y = q.front().second.first; int x = q.front().second.second;
            int bit = q.front().first;
            int dist = dp[bit][y][x];
            
            if (bit == (1 << (idx - 1))  - 1){ // 모든곳 다 방문
                cout << dist << endl;
                break;
            }

            q.pop();

            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                int tmpbit = bit;
                if(ny >= 0 && ny < h && nx >= 0 && nx < w){
                    if(b[ny][nx] == -1) continue; // 가구라 갈 수 없다.
                    if(b[ny][nx] > 0) { // 이동하는 장소가 더러운 장소라면, 비트마스크 추가
                        tmpbit = tmpbit | (1 << (b[ny][nx] - 1));
                    }
                    if(!dp[tmpbit][ny][nx]){
                        dp[tmpbit][ny][nx] = dist + 1;
                        q.push({tmpbit, {ny, nx}});
                    }
                }
            }
        }
        if(q.empty()) cout << -1 << endl;
    }
    return 0;
}