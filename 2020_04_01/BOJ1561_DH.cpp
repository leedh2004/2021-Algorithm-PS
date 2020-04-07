#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> v(m);
    for(int i=0; i<m; i++)
        cin >> v[i];
    if(n <= m){
        cout << n;
        return 0;
    } 
    ll left = 0;
    ll right = 60000000000;
    ll g;
    while(left < right){
        ll mid = (left+right+1)/2;
        ll num = 0;
        // cout << left << " " << right << endl;
        for(int i=0; i<m; i++){
            num += ((mid / v[i]) + 1); // mid분에 num명 태울 수 있다.
        }
        // cout << num << endl;
        if(num >= n){
            g = mid;
            right = mid - 1;
        }    
        else {
            left = mid;
        }
    }
    //g = left;
    // cout << g << endl;
    ll b = g - 1;
    ll tmp = 0;
    for(int i=0; i<m; i++)
        tmp += ((b / v[i]) + 1);
    // cout << tmp << endl;
    ll k = n - tmp; // 3
    for(int i=0; i<m; i++){
        ll j = b / v[i];
        ll l = g / v[i];
        if(j != l) k--;
        if(k == 0){
            cout << i + 1;
            break;
        }
    }
    return 0;
}