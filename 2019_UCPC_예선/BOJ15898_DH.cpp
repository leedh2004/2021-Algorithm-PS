#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n;

pair<int, char> p[10][4][4][4];

void rotate(int n){
    for(int i=1; i<4; i++){
        for(int y=0; y<4; y++){
            for(int x=0; x<4; x++){
                p[n][i][y][x] = p[n][i-1][x][3-y];
            }
        }
    }
}

int ans = 0;
int sum(vector<vector<pair<int, char>>> v){
    int ret = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(v[i][j].second == 'R') ret += 7 * v[i][j].first;
            if(v[i][j].second == 'B') ret += 5 * v[i][j].first;
            if(v[i][j].second == 'G') ret += 3 * v[i][j].first;
            if(v[i][j].second == 'Y') ret += 2 * v[i][j].first;
        }
    }
    return ret;
}

vector<vector<pair<int, char>>> paint(int idx, int rotate_idx, int starty, int startx, vector<vector<pair<int, char>>> v){
    for(int i=0+starty; i<4+starty; i++){
        for(int j=0+startx; j<4+startx; j++){
            if(p[idx][rotate_idx][i-starty][j-startx].second != 'W') v[i][j].second = p[idx][rotate_idx][i-starty][j-startx].second;
            v[i][j].first += p[idx][rotate_idx][i-starty][j-startx].first;
            if(v[i][j].first < 0) v[i][j].first = 0;
            if(v[i][j].first > 9) v[i][j].first = 9;
        }
    }
    return v;
}

void dfs(int a, int b, int c, int cnt, vector<vector<pair<int, char>>> v){
    if(cnt == 3){
        int ret = sum(v);
        if(ret > ans) ans = ret;
        return;
    }

    int select[3] = {a, b, c};

    for(int idx=0; idx<4; idx++){ // rotate_idx
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                vector<vector<pair<int, char>>> nv = paint(select[cnt], idx, i, j, v);
                dfs(a, b, c, cnt+1, nv);
            }
        }
    }
    
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                cin >> p[i][0][j][k].first;
            }
        }
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                cin >> p[i][0][j][k].second;
            }
        }
        rotate(i);
    }
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                // i, j, k 선택
                vector<vector<pair<int, char>>> map(5, vector<pair<int, char>>(5));
                for(int i=0; i<5; i++)
                    for(int j=0; j<5; j++)
                        map[i][j] = {0, 'W'};

                // board 초기화
                dfs(i, j, k, 0, map);
                dfs(i, k, j, 0, map);
                dfs(j, i, k, 0, map);
                dfs(j, k, i, 0, map);
                dfs(k, i, j, 0, map);
                dfs(k, j, i, 0, map);
            }
        }
    }
    cout << ans;
    return 0;
}