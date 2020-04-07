#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int dist[301][301]; // dist[n][v] n번 거쳤을때 v로 도달하는 최대값
vector<int> v[301];
int cost[301][301];
int ans;

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0; i<k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a < b){
            v[a].push_back(b);
            cost[a][b] = max(cost[a][b], c);
        }
    }

    queue<pair<int, pair<int, int> > > q; // here, next, cnt

    for(int i=0; i<v[1].size(); i++){
        int next = v[1][i];
        q.push({1, {next, 1}});
    }
    
    while(!q.empty()){
        int here = q.front().first;
        int next = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        if(cnt > m) continue;
        if(dist[cnt+1][next] < dist[cnt][here] + cost[here][next]){
            dist[cnt+1][next] = dist[cnt][here] + cost[here][next];
            for(int i=0; i<v[next].size(); i++){
                int nnext = v[next][i];
                q.push({next, {nnext, cnt+1}});
            }
        }
    }
    for(int i=2; i<=m; i++) ans = max(ans, dist[i][n]);
    cout << ans;
    return 0;
}