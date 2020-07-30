#include <iostream>
#include <cstring>
using namespace std;

int b[1001][1001];
int dp[1005][1005];
int dp2[1005][1005];

int ans = -1;
int dx[3] = {1, 1, 2};
int dy[3] = {1, -1, 0};
int n, m;

int dfs(int y, int x){ 
    if (dp[y][x] != -1) return dp[y][x];
    if (y >= n || y < 0 || x >= m) return 0;
    dp[y][x] = b[y][x];
    for(int i=0; i<3; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < n && nx >= 0 && nx < m){
            if(i == 2) dp[y][x] = max(dp[y][x], b[y][x] + b[y][x+1] + dfs(ny, nx));
            else 
            dp[y][x] = max(dp[y][x], b[y][x] + dfs(ny, nx));
        }
    }
    return dp[y][x];
}

int dfs2(int y, int x){
    // y.5라고 생각해 우선
    if (dp2[y][x] != -1) return dp2[y][x];
    if (y >= n+1 || y < -1 || x >= m) return 0;
    dp2[y][x] = max(b[y+1][x] + dfs2(y+1, x+1), b[y][x] + dfs2(y-1, x+1));
    return dp2[y][x];
}

int main(){
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> b[i][j];
    // dp[y][x] = b[y][x] + max(dp[y+1][x+1], dp[y-1][x+1], dp[y][x+2])    
    for(int i=-1; i<n; i++){
        for(int j=0; j<m; j++){
            ans = max(ans, dfs(i, j));
            // cout << dp[i][j] << " ";
            ans = max(ans, dfs2(i, j));
            //cout << dp2[i][j] << endl;
        }
        //cout << endl;
    }
    //cout << int(-0.5);
    cout << ans;
    return 0;
}