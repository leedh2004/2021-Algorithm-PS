#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
vector<pair<int, int> > v;

int dp[1001][1001]; 
int n, w;
// dp[i][j] 는 1번 경찰차가 i번째 사건 2번 경찰차가 j번째 사건에 있을 때 최소거리
// dp[i][j] = min(dp[i-1][j] + dist, dp[i][j-1] + dist)

int distance(int i, int j){
    return abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
}

int go(int i, int j){ 
    int cur = max(i, j);
    if(cur == w+1) return 0;
    int& ret = dp[i][j];
    if(ret != -1) return ret;
    int d1 = go(cur+1, j) + distance(cur+1, i);
    int d2 = go(i, cur+1) + distance(cur+1, j);
    return ret = min(d1, d2);
}

void print(int i, int j){
    int cur = max(i, j);
    if(cur == w+1) return;
    int d1 = go(cur+1, j) + distance(cur+1, i);
    int d2 = go(i, cur+1) + distance(cur+1, j);
    if(d1 < d2){
        cout << "1\n";
        print(cur+1, j);
    }
    else{
        cout << "2\n";
        print(i, cur+1);
    }
}

int main(){

    cin >> n >> w;
    v.push_back({1,1});
    v.push_back({n,n});
    for(int i=0; i<w; i++){
        int y, x;
        cin >> y >> x;
        v.push_back({y, x});        
    }
    
    memset(dp, -1, sizeof(dp));
    cout << go(0, 1) << '\n';
    print(0,1);
    return 0;
}