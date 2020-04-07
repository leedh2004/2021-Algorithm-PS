#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans = 0;
        vector<ll> v(n);
        vector<ll> dp(n); // dp[i]는 i이전부터 i에서 끝날때 최소값
        vector<ll> dp2(n);
        for(int i=0; i<n; i++) {
            cin >> v[i];
            ans += v[i];
        }
        ll tmp = 0;
        ll tmp2 = 0;
        dp[0] = v[0];
        dp2[0] = v[0]; // i에서 끝날때 최대값
        tmp = min(tmp, dp[0]);
        for(int i=1; i<n; i++){
            dp[i] = min(v[i], dp[i-1]+v[i]);
            dp2[i] = max(v[i], dp2[i-1]+v[i]);
            tmp = min(tmp, dp[i]);
            tmp2 = max(tmp2, dp2[i]);
        }
        cout << max(ans - tmp, tmp2) << '\n';
    }
    return 0;
}