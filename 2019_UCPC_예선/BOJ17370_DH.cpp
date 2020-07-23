#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int a[200][200];
int visited[200][200];
int dx[] = {0, 0, 1, 1, -1, -1};
int dy[] = {2, -2, 1, -1, 1, -1};
// type 0 => 2, 4
// type 1 => 3 ,5
// type 2 => 0, 3
// type 3 => 1, 2
// type 4 => 0, 5 
// type 5 => 4, 1
int t[6][2] = {{2, 4}, {3, 5}, {0, 3}, {1, 2}, {0, 5}, {4, 1}};
int ans;
int n;

void dfs(int y, int x, int type, int cnt){
    if(cnt == n)
        return;
    for(int i=0; i<2; i++){
        int ntype = t[type][i];
        int nx = x + dx[ntype];
        int ny = y + dy[ntype];
        if(visited[ny][nx]){
            if(cnt == n - 1){
                ans++;
            }
        }else{
            s.push({ny, nx});
            visited[ny][nx] = 1;
            dfs(ny, nx, ntype, cnt+1);
            visited[ny][nx] = 0;
            s.pop();
        }
    }
}

int main(){
    cin >> n;
    visited[100][100] = 1; visited[102][100] = 1;
    dfs(102, 100, 0, 0);
    cout << ans;
    return 0;
}