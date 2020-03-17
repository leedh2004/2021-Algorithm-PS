#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
 // 1 1 3 4 5 .. 3
int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    ll ans = 0;
    ll val = 1;
    for(int i=0; i<n; i++){
        if(v[i] >= val) {
            ans += (v[i] - val);
            val++;
        }
    }
    cout << ans;
    return 0;
}