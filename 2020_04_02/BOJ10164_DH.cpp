#include <iostream>
using namespace std;
typedef long long ll;
ll dp[20][20];

int main(){

    int n, m, k;
    cin >> n >> m >> k; // 1 2 2
    int y, x; 
    y = k / m + 1; 
    x = k % m; 
    if(k % m == 0){
        y--;
        x = m;
    }
    if(k == 0){
        y = 1;
        x = 1;
    }

    for(int i=1; i<=m; i++)
        dp[1][i] = 1;
    
    for(int i=1; i<=n; i++)
        dp[i][1] = 1;

    for(int i=2; i<=n; i++)
        for(int j=2; j<=m; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];

    ll ans = dp[y][x] * dp[n-y+1][m-x+1];
    cout << ans;

    return 0;
}