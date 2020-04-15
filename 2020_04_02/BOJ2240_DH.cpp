#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1001][31][2];
int T[1001];

//dp[t][w][0] = (dp[t-1][w][0], dp[t-1][w-1][1]) + ?
//dp[t][w][1] = (dp[t-1][w-1][0], dp[t-1][w][1]) + ?

int main(){
    //memset(dp, -1, sizeof(dp));
    int t, w;
    cin >> t >> w;
    for(int i=0; i<t; i++) cin >> T[i];
    if(T[0] == 1)
        dp[0][0][0]++;
    else
        dp[0][1][1]++; 
    int ans = 1;
    for(int i=1; i<t; i++){
        for(int j=0; j<=w; j++){
            if(j>0){
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1]);
                dp[i][j][1] = max(dp[i-1][j-1][0], dp[i-1][j][1]);
            }else{ // j == 0
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][1] = dp[i-1][j][1];
            }
            if(T[i] == 1) dp[i][j][0]++;
            else dp[i][j][1]++;
            ans = max(ans, dp[i][j][1]);
            ans = max(ans, dp[i][j][0]);
        }
    }
    cout << ans;
    return 0;
}