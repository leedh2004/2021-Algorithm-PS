#include <iostream>

#define MOD (1000000003)
using namespace std;

int dp[1005][1005];

int main(){

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=3; i++)
        dp[i][1] = i; // dp[n][k] 는 n개중에 k개를 선택하는 경우의 수
    
    for(int i=4; i<=n; i++){
        int maxChoose = i / 2;
        for(int choose=1; choose <= maxChoose; choose++){
            if(choose == 1) dp[i][choose] = i;
            else dp[i][choose] = (dp[i-2][choose-1] + dp[i-1][choose]) % MOD;
        }
    }

    cout << dp[n][k];
    return 0;
}