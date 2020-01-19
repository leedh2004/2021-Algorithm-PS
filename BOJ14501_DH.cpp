#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int t[16], p[16];
int dp[16]; // dp[day] day날 상담을 할 경우 최대 가격

int ans = 0;
const int INF = 987654321;

int solve(int day){
    int& ret = dp[day];
    if(ret != -1) return ret;
    if(day + t[day] > n + 1) return ret = -INF;
    ret = p[day];
    int temp = ret;

    for(int i=day+t[day]; i<=n; i++)
        temp = max(temp, ret + solve(i));
        
    ret = temp;
    
    ans = max(ans, ret);
    return ret;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> t[i] >> p[i];
    }
    for(int i=1; i<=n; i++) solve(i);
        cout << ans;
    return 0;
}