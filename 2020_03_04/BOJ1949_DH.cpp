#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> nxt[10001];
vector<int> a[10001]; // 자식을 저장
int p[10001]; // 사람 수
int visited[10001];
int dp[10001][2];

void dfs(int here){
    visited[here] = 1;
    for(int i=0; i<a[here].size(); i++){
        int child = a[here][i];
        if(!visited[child]){
            nxt[here].push_back(child);
            dfs(child);
        }
    }
}

int solve(int here, bool chk){
    int &ret = dp[here][chk];
    if (ret != 0) return ret; // 이거 안하면 시간초과 남, 저번에 안난다고 한 것 같은데..
    if (chk) ret = p[here];

    if(!chk){
        for(int i=0; i<nxt[here].size(); i++){
            int child = nxt[here][i];
            ret += max(solve(child, false), solve(child, true));
        }
    }else{ // 체크가 된 경우 
        for(int i=0; i<nxt[here].size(); i++){
            int child = nxt[here][i];
            ret += solve(child, false);
        }
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i];
    for(int i=0; i<n-1; i++){
        int c, d; cin >> c >> d;
        a[c].push_back(d);
        a[d].push_back(c);
    }
    dfs(1);
    int ans = 0;
    ans = max(solve(1, true), solve(1, false));
    cout << ans;
    return 0;
}