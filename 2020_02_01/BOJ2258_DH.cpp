#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll> > v(n); //first 가격, second 무게
    for(int i=0; i<n; i++){
        cin >> v[i].second >> v[i].first;
        v[i].second *= -1;
    }
    sort(v.begin(), v.end());
    ll w = 0; // 도달 가능 무게
    ll ans = 2147483648;
    bool flag = false;
    int before = 0;
    for(int i=0; i<n; i++){
        w -= v[i].second;
        if (i != 0 && v[i].first == v[i-1].first){
            before += v[i-1].first;
        }else{
            before = 0;
        }
        if(w >= m) ans = min(ans, before + v[i].first), flag = true;
    }
    if (flag) cout << ans;
    else cout << -1;
    return 0;
}