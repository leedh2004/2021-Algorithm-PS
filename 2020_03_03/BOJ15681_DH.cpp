#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> edge[100001];
int dp[100001];
int visited[100001];

int solve(int t){
    
    int& ret = dp[t];
    if (ret != -1) return ret;
    
    visited[t] = 1;
    ret = 1;

    for(int i=0; i<edge[t].size(); i++){
        int next = edge[t][i];
        if(visited[next]) continue;
        else ret += solve(next);    
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, r, q;
    memset(dp, -1, sizeof(dp));
    cin >> n >> r >> q;
    
    n--;
    while(n--){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    solve(r);

    while(q--){
        int t;
        cin >> t;
        cout << solve(t) << '\n';
    }

    return 0;
}