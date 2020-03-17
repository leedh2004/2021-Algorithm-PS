#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> edge[1000001];
vector<int> dirNode[1000001];
int dp[1000001][2];
bool visited[1000001]; 

void dfs(int here){ // 단방향 트리를 저장
    visited[here] = 1;
    for(int i=0; i<edge[here].size(); i++){
        int next = edge[here][i];
        if(!visited[next]){
            dirNode[here].push_back(next);
            dfs(next);
        }
    }
}

int Solve(int here, bool chk){
    if(dp[here][chk] != -1) return dp[here][chk];
    if(chk){
        int result = 0;
        for(int i=0; i<dirNode[here].size(); i++){
            int next = dirNode[here][i];
            result += min(Solve(next, false), Solve(next, true));
        }
        return dp[here][chk] = result + 1;
    }else{
        int result = 0;
        for(int i=0; i<dirNode[here].size(); i++){
            int next = dirNode[here][i];
            result += Solve(next, true);
        }
        return dp[here][chk] = result;
    }
    return dp[here][chk] = 0;
}

int main(){
    int n; cin >> n;
    for(int i=0; i<n-1; i++){
        int p, c;
        cin >> p >> c;
        edge[p].push_back(c);
        edge[c].push_back(p);
    }
    memset(dp, -1, sizeof(dp));
    dfs(1);
    cout << min(Solve(1, false), Solve(1, true));
    return 0;
}