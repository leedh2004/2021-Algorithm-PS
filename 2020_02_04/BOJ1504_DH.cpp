#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 987654321;

struct edge{
    int to;
    int distance;
};
typedef long long ll;

vector<edge> v[801];
int n;

ll dijikstra(int start, int end){
    ll d[801];
    for(int i=1; i<=n; i++) d[i] = INF; // 2번 노선부터 n번 노선까지의 거리를 무한대로 설정한다.
    d[start] = 0;
    bool visited[801];
    for(int i=1; i<=n; i++) visited[i] = 0;
    priority_queue<pair<ll,int>> pq; // min_heap으로 하기위해 음수를 넣어준다. first distance, second 현재 노선
    pq.push({0, start});
    while(!pq.empty()){
        int here = pq.top().second;
        pq.pop();
        if(visited[here]) continue;
        visited[here] = 1;
        for(int i=0; i<v[here].size(); i++){
            int next = v[here][i].to;
            ll next_distance = d[here] + v[here][i].distance;
            if(next_distance < d[next]){
                d[next] = next_distance;
                pq.push({-next_distance, next});
            }
        }
    }
    return d[end];
}

int main(){

    int e;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    int f, g;
    cin >> f >> g;
    
    ll one_to_f = dijikstra(1, f);
    ll one_to_g = dijikstra(1, g);
    ll g_to_f =dijikstra(g, f);
    ll f_to_g = dijikstra(f, g);
    ll g_to_n = dijikstra(g, n);
    ll f_to_n = dijikstra(f, n);
    // cout << one_to_f << endl;
    // cout << one_to_g << endl;
    // cout << g_to_f << endl;
    // cout << f_to_g << endl;
    // cout << g_to_n << endl;
    // cout << f_to_n << endl;
    ll answer = min(one_to_f + f_to_g + g_to_n, one_to_g + g_to_f + f_to_n );
    if(answer >= INF) answer = -1;
    cout << answer;

    return 0;
}