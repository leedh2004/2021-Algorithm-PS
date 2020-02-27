#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;

struct edge{
    int from;
    int to;
    int cost;
};

vector<edge> e;
int d[601];

int main(){

    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back({a, b, c});
    }
    for(int i=1; i<=n; i++) d[i] = INF;
    d[1] = 0;
    bool flag = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<e.size(); j++){
            int from = e[j].from;
            int to = e[j].to;
            int cost = e[j].cost;
            if(d[from] != INF && d[from] + cost < d[to]){
                d[to] = d[from] + cost;
                if(i == n - 1) flag = true;
            }
        }
    }
    if(flag) cout << -1;
    else{
        for(int i=2; i<=n; i++, cout << endl){
            if(d[i] != INF) cout << d[i];
            else cout << -1;
        }
    }
    return 0;
}