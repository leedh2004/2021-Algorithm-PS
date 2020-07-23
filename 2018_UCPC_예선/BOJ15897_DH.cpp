#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll cur = 1;
    ll ans = n;
    n--;
    ll before = -1;
    ll bm = -1;
    while(cur <= n){
        ll val = n / cur;
        ll m = n % cur;
        //cout << "val: " << val << " mod: " << m << " cur: " << cur << endl;
        if(before == val){
            ll diff = bm - m; // 등차 수열의 차이값
            ll cnt = bm / diff + 1;
            ans += (cnt - 1)* val;
            cur += cnt - 1;
        }else{
            before = val;
            bm = m;
            cur++;
            ans += val;
        }
    }
    cout << ans;
    return 0;
}