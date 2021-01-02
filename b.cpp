#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dp[26][26][2]; // dp[0][1][0] 은 0,1에 위 아래 방향 도착, dp[0][1][1]은 0,1에 오른쪽 왼쪽 방향 도착
int n;

void ppp(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << max(dp[i][j][0], dp[i][j][1]) << " ";
        }
        cout << endl;
    }
}


void dfs(int y, int x, bool updown, int value, vector<vector<int>>& b){
    cout << "======\n";

    cout << y << " " << x << " " << updown << " " << value << endl;
    if(dp[y][x][updown] == -1) dp[y][x][updown] = value;
    else{
        if(dp[y][x][updown] <= value) return;
        else dp[y][x][updown] = value;
    }
    ppp();
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < n && ny >= 0 && nx < n && nx >= 0 && b[ny][nx] == 0){
            bool next_up;
            if (i < 2) next_up = false;
            else next_up = true;
            
            int new_value;
            if(next_up == updown) new_value = value + 100;
            else new_value = value + 600;
            dfs(ny, nx, next_up, new_value, b);
        }
    }
}


int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();
    memset(dp, -1 ,sizeof(dp));
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    
    if(!board[0][1]) dfs(0, 1, false, 100, board);
    if(!board[1][0]) dfs(1, 0, true, 100, board);

    if(dp[n-1][n-1][0] == -1) return dp[n-1][n-1][1];
    else if(dp[n-1][n-1][1] == -1) return dp[n-1][n-1][0];
    else return min(dp[n-1][n-1][0], dp[n-1][n-1][1]);
}

int main(){
    vector<vector<int>> v(3,vector<int>(3, 0));
    int answer = solution(v);
    cout << answer;
    return 0;
}