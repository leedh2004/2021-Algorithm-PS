#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
ll dp[1<<15][101];

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    
    int n;
    cin >> n;
    vector<string> v(n);
    vector<int> len(n);
    vector<int> a(n, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
        len[i] = v[i].size();
    }
    int k; cin >> k;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<len[i]; j++){
            a[i] = a[i] * 10 + (v[i][j] -'0');
            a[i] %= k; // i번째 수의 모듈러 값
        }
    }
    vector<int> ten(51);
    ten[0] = 1;
    for(int i=1; i<=50; i++){
        ten[i] = ten[i-1] * 10;
        ten[i] %= k; // 10의 i승의 모듈러 값 
    }
    
    dp[0][0] = 1;
    for(int i=0; i < (1 << n); i++){
        for(int j=0; j<k; j++){
            for(int l=0; l<n; l++){
                if ( (i & (1 << l)) == 0){
                    int next = j * ten[len[l]];
                    next %= k;
                    next += a[l];
                    next %= k;
                    dp[i|(1<<l)][next] += dp[i][j];
                }
            }
        }
    }
    ll t1 = dp[(1<<n)-1][0];
    ll t2 = 1;
    for(ll i=2; i<=n; i++) t2 *= i;
    ll g = gcd(t1, t2);
    t1 /= g; t2 /= g;
    cout << t1 << "/" << t2 << endl;
    return 0;
}