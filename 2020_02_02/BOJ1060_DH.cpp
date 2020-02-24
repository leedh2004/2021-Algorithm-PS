#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ll n, t;
    cin >> t;
    vector<ll> l(t);
    vector<ll> ans; // lucky set임.
    for(ll i=0; i<t; i++){
        cin >> l[i];
        ans.push_back(l[i]);
    }    
    cin >> n;
    sort(l.begin(), l.end());
    ll start = 1;
    ll end = -1;
    vector<pair<ll, ll> > v; //unlucky 구간을 담는다. v[i].first 는 언럭키 구간개수, v[i].second는 값
    map<ll, ll> m; // map[i] = i의 부분집합 개수
    for(ll i=0; i<l.size(); i++){
        end = l[i] - 1;
        if(start == end) {
            ans.push_back(start);
            start = l[i] + 1;
            continue;
        }
        ll c = 0;
        //else if(start > 100) break; // 일단 이건 나중에 생각해보자.
       for(ll i=start; i <= (start + end)/2 && c < 50; i++){
            ll cnt = end - i;
            cnt += (end - i + 1) * (i-start);
            m[i] = cnt;
            v.push_back({m[i], i});
            if ( i != end - c)
                v.push_back({m[i], end-c});
            c++;
        }
        start = l[i] + 1;
    }
    sort(ans.begin(), ans.end());
    sort(v.begin(), v.end());
    for(ll i=0; i<v.size(); i++) {
        ans.push_back(v[i].second);
    }
    end = end + 2;
    while(ans.size() < n){
        ans.push_back(end++);
    }
    for(ll i=0; i<n; i++) cout << ans[i] << " ";
    return 0;
}