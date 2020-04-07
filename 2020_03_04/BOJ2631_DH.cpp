#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int dp[201];
int ans = -1;
int n;

int lis(int a){ // dp[a] 으로 시작하는 LIS 길이

    int &ret = dp[a];
    if(ret != 0) return ret;
    ret = 1;

    for(int i=a+1; i<n; i++){
        if(v[a] < v[i]){
            ret = max(ret, lis(i) + 1);
        }
    }

    ans = max(ans, ret);
    return ret;
}


int main(){
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<n; i++) lis(i);
    cout << n - ans;
    return 0;
}