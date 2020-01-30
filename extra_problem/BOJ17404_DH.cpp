#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int rgb[1001][3];
int dp[1001][3][3]; // dp[n][i] n번째 집이 i번째 색일때, 최소값
// dp[n][i] = min(dp[n-1][!i] + rgb[n][i])
const int inf = 987654321;
int n;

int solve(int cur, int color, int start){
    int& ret = dp[cur][color][start];
    if(ret != -1) return ret;
    
    if(cur == n-1) {
        if ( color == start ) return inf;
        else return rgb[cur][color];
    }

    ret = inf;

    for(int i=0; i<3; i++){
        if (i == color) continue;
        ret = min(ret, solve(cur+1, i, start) + rgb[cur][color]);
    }

    return ret;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    cout << min(solve(0, 0, 0), min(solve(0, 1, 1), solve(0, 2, 2)));
    return 0;
}