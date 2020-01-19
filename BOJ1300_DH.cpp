#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;

    ll ans;
    ll left = 1, right = k;

    while(left <= right){
        ll mid = (left + right) / 2;
        ll cnt = 0;
        for(ll i=1; i<=n; i++) cnt += min(mid / i, n);
        if (cnt < k) left = mid + 1;
        else ans = mid, right = mid - 1;   
    }

    cout << ans;
    return 0;
}