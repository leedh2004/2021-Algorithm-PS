#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int dp[101][1001]; // dp[i][x] 는 i번째에서 x 볼륨에 도달할 수 있는지를 나타냄.

int main(){
    int n, s, m;
    cin >> n >> s >> m;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];
    memset(dp, -1, sizeof(dp));
    dp[0][s] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if( j - v[i] >= 0 && dp[i-1][j-v[i]] == 1){
                dp[i][j] = 1;
            }
            if( j + v[i] <= m && dp[i-1][j+v[i]] == 1){
                dp[i][j] = 1;
            }
        }
    }
    for(int i=m; i>=0; i--){
        if(dp[n][i] != -1){
            cout  << i << endl;
            return 0;
        }
    }
    cout << -1;
    return 0;
}