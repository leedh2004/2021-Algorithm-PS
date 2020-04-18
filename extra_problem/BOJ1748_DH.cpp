#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main(){

    ll n;
    cin >> n;
    ll ans = 0;
    ll cnt = 1;

    while(cnt){
        if(n < pow(10, cnt)) {
            ans += (n-pow(10,cnt-1)+1)*cnt;
            cout << ans;
            return 0;
        }
        ans += (pow(10,cnt) - pow(10,cnt-1)) * cnt;
        cnt++;    
    }

    return 0;
}