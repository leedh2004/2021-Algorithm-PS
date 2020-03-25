#include <iostream>
#include <algorithm>

using namespace std;
int dp[1001][10001];
const int MOD = 1000000007;

int main(){

    int n, c;
    cin >> n >> c;

    for(int i=2; i<=n; i++){
        dp[i][0] = 1;
        for(int j=1; j <= 10000 && j<=(i*i-1)/2; j++){ // 최대 혼란도 n 컴비네이션 2
            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%MOD;
            if(j-i >= 0)
                dp[i][j] = ((dp[i][j])-(dp[i-1][j-i])+MOD)%MOD;
        }
    }

    cout << dp[n][c];
    return 0;
}