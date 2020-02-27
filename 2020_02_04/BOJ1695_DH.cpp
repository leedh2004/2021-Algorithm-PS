#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[5001][5001]; // dp[i][j] 는 i부터 j까지 펠린드롬을 만드는 필요한 최소 개수
vector<int> v;

int solve(int i, int j){
    int& ret = dp[i][j];
    if(ret != -1) return ret;
    ret = 0;
    if(i >= j) return ret;
    
    if(v[i] == v[j]) return ret += solve(i+1, j-1);
    else return ret = min(solve(i+1, j), solve(i, j-1)) + 1;
    
}

int main(){
    int n;
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n-1);
    return 0;
}