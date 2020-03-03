#include <iostream>
#include <vector>
using namespace std;
int n;
typedef long long ll;

vector<vector<ll>> E;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> ret(n, vector<ll>(n, 0));
    for(int i=0; i<n; i++){
        for(int l=0; l<n; l++){
            for(int j=0; j<n; j++){
                ret[i][l] += ((A[i][j] % 1000) * (B[j][l] % 1000)) % 1000;
            }
        }
    }
    return ret;
}

vector<vector<ll>> solve(vector<vector<ll>> A, ll b){
    if(b == 1) return A;

    if(b % 2 == 0){
        vector<vector<ll>> tmp = solve(A, b/2);
        return multiply(tmp, tmp);
    }else{
        vector<vector<ll>> tmp = solve(A, b-1);
        return multiply(tmp, A);
    }
}

int main(){
    ll  b;
    cin >> n >> b;
    
    for(int i=0; i<n; i++){
        vector<ll> v;
        for(int j=0; j<n; j++){
            if(i==j) v.push_back(1);
            else v.push_back(0);
        }
        E.push_back(v);
    }

    vector<vector<ll>> A(n, vector<ll>(n, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> A[i][j];
    vector<vector<ll>> ans = solve(A, b);

    for(int i=0; i<n; i++, cout<<endl)
        for(int j=0; j<n; j++)
            cout << ans[i][j]%1000 << " ";
    return 0;
}