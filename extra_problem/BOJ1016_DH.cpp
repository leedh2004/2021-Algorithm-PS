#include <iostream>
#include <cmath>
using namespace std;
int chk[1000001];
int chk2[1000001];

typedef long long ll;

int main(){
    ll a, b;
    cin >> a >> b;
    ll ans = b - a + 1;

    for(ll i=2; i*i <= b; i++){
        if (chk[i]) continue;
        for(ll j=i; j*j <= b; j+=i) chk[j] = 1;
        for(ll j=(a/(i*i))*(i*i); j<=b; j+=i*i){ // j를 a보다 더 큰 i*i의 배수로 바꿔야 함.
            if (j >= a && !chk2[j-a]) 
                ans--, chk2[j-a] = 1;
        }
    }

    cout << ans;
    return 0;
}