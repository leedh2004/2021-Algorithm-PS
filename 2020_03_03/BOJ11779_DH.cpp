#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <climits>

typedef long long ll;

using namespace std;


priority_queue<pair<int, pair<int, int>>> pq; // w, from, to
vector<pair<int, int>> edges[1001];
stack<int> ans;
ll dist[1001];
int st[1001];
int cnt;
const ll INF = LLONG_MAX;

void dfs(int here, int end){
    ans.push(here); cnt++;
    if(here == end) return;
    dfs(st[here], end);
}

int main(){
    
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) dist[i] = INF; // 정점 무한대 초기화

    while(m--){
        int from, to, w;
        cin >> from >> to >> w;
        edges[from].push_back({to, w});
    }

    int from, to;
    cin >> from >> to;
    dist[from] = 0;
    for(int i=0; i<edges[from].size(); i++){
        int to = edges[from][i].first;
        int w = edges[from][i].second;
        pq.push({-w, {from, to}});
    }

    while(!pq.empty()){
        int w = -pq.top().first; // 양수로 전환
        int from = pq.top().second.first;
        int to = pq.top().second.second;
        pq.pop();
        if(dist[to] > dist[from] + w){ // dist[to] == INF로 했더니 안됐다. 왤까?
            dist[to] = dist[from] + w;
            st[to] = from;
            for(int i=0; i<edges[to].size(); i++){
                int next = edges[to][i].first;
                int w = edges[to][i].second;
                pq.push({-w, {to, next}});
            }
        }
    }
    cout << dist[to] << '\n';
    dfs(to, from);
    cout << cnt << '\n';
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}