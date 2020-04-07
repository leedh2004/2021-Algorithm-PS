#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[10001][2];
int visited[10001];

vector<int> v[10001];
vector<int> d[10001]; // 1을 기준으로 단방향 트리로 바꾼다.
vector<int> w;
vector<int> ans;

void dfs(int val){
    visited[val] = 1;
    for(int i=0; i<v[val].size(); i++){
        int child = v[val][i];
        if(!visited[child]){
            d[val].push_back(child);
            dfs(child);
        }
    }    
}

int solve(int here, bool flag){
    int& ret = dp[here][flag];
    if(ret != -1) return ret;
    ret = 0;
    if(flag){
        ret += w[here];
        for(int i=0; i<d[here].size(); i++){
            int child = d[here][i];
            ret += solve(child, !flag);
        }
    }else{
        for(int i=0; i<d[here].size(); i++){
            int child = d[here][i];
            ret += max(solve(child, true), solve(child, false));
        }
    }
    return ret;
}
void tracking(int here, bool flag){
    if(flag){
        ans.push_back(here);
        for(int i=0; i<d[here].size(); i++){
            int child = d[here][i];
            tracking(child, !flag);
        }
    }else{
        for(int i=0; i<d[here].size(); i++){
            int child = d[here][i];
            if (dp[child][1] > dp[child][0]) tracking(child, 1);
            else tracking(child, 0);
        }
    }
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    w.resize(n+1);
    for(int i=1; i<=n; i++) cin >> w[i];
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    int a = solve(1, 0); 
    int b = solve(1, 1);
    if(a > b){
        tracking(1, 0);
        sort(ans.begin(), ans.end());
        cout <<  a << '\n';
        for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    }else{
        tracking(1, 1);
        sort(ans.begin(), ans.end());
        cout <<  b << '\n';
        for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    }
    return 0;
}