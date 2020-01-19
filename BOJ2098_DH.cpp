#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[16][16];
int dp[1<<16][16]; // dp[stat][cur] stat 상태이고, 현재 위치가 cur 일 때 최소값
int n;
const int inf = 1e9;

int go(int cur, int stat){
    
    if( stat == (1 << n) - 1 )
        return a[cur][0] ? a[cur][0] : inf;
    
    int& ret = dp[stat][cur];
    if(ret != -1) return ret;
    ret = inf;

    for(int i=0; i<n; i++){
        if(a[cur][i] && (stat & (1 << i)) == 0){
            ret = min(ret, go(i, stat | (1 << i)) + a[cur][i]);
        }
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];
    memset(dp, -1, sizeof(dp));
    cout << go(0, 1);
    return 0;
}