#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>

struct edge{
    int to;
    int weight;
};
int dist[401][401];
int a[401][401];
using namespace std;
const int INF = 987654321;
priority_queue<pair<int, pair<int, int> > > pq;
vector<edge> v[401];
int main(){
    int V, E;
    // 플로이드 와샬로 최소거리를 구한다음, 거기서 출발지점으로 돌아올 수 있는지를 모두 판별하면 될듯.
    // 반박시 정상수
    cin >> V >> E;
    for(int i=0; i<401; i++){
        for(int j=0; j<401; j++){
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }

    for(int i=0; i<E; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        dist[from][to] = cost;
    }

    for(int k=1; k<=V; k++){
        for(int i=1; i<=V; i++){
            for(int j=1; j<=V; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int ans = INF;
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            if(i==j) continue;
            if(dist[i][j] + dist[j][i] < INF) ans = min(ans, dist[i][j] + dist[j][i]);
        }
    }
    if(ans == INF) cout << -1;
    else cout << ans;
    return 0;
}