// 삼성기출문제 BFS DFS
#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[10][10];
int ans = -1;
int row, col;
vector<pair<int, int> > v;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[10][10];

void dfs (int y, int x){
    int ret = 0;
    visited[y][x] = 1;

    if(arr[y][x] == 0)
        arr[y][x] = 3;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if ( ny >= 0 && ny < row && nx >= 0 && nx < col && arr[ny][nx] == 0 && !visited[ny][nx])
            dfs(ny, nx);
    }
}

int count(){
    int cnt = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == 0) cnt++;
            if(arr[i][j] == 3) arr[i][j] = 0;
        }
    }
    return cnt;
}

int main(){
    cin >> row >> col;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0) v.push_back({i, j});  
        }
    }
    int size = v.size();
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            for(int k=j+1; k<size; k++){
                memset(visited, 0, sizeof(visited));
                arr[v[i].first][v[i].second] = 1;
                arr[v[j].first][v[j].second] = 1;
                arr[v[k].first][v[k].second] = 1;
                int ret = size;
                for(int r=0; r<row; r++){
                    for(int c=0; c<col; c++){
                        if (arr[r][c] == 2 && !visited[r][c]) dfs(r, c);
                    }
                }
                ans = max(ans, count());
                arr[v[i].first][v[i].second] = 0;
                arr[v[j].first][v[j].second] = 0;
                arr[v[k].first][v[k].second] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}