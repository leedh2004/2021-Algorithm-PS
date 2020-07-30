#include <iostream>
#include <queue>
#include <utility>


using namespace std;

int parent[100001];

void init(int n){
    for(int i=1; i<=n; i++) parent[i] = i;
}

int getParent(int a){
    if(parent[a] == a) return a;
    else return parent[a] = getParent(parent[a]);
}

bool _union(int a, int b){
    int pa = getParent(a);
    int pb = getParent(b);
    if(pa == pb) return false;
    int m = min(pa, pb);
    parent[pa] = parent[pb] = m;
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    init(n);
    priority_queue<pair<int, pair<int, int>>> pq;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, {a, b}});
    }
    // MST 만들고 가장 큰 선분 지우면 될듯?..
    // 싸이클 판별은 어떻게할까
    int sum = 0;
    int M = -1; // MAX
    for(int i=0; i<n-1; i++){
        while(!pq.empty()){
            int cost = -pq.top().first;
            int a = pq.top().second.second;
            int b = pq.top().second.first;
            pq.pop();
            if(_union(a, b)){
                M = max(M, cost);
                sum += cost;
            }
        }
    }
    cout << sum - M;
    return 0;
}