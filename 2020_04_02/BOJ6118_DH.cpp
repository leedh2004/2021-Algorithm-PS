#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;
vector<int> v[20001];
int dist[20001];

int main(){
    int n, m;
    cin >> n >> m;
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<pair<int, int> > q;
    for(int i=0; i<v[1].size(); i++){
        q.push({v[1][i], 1});
    }
    while(!q.empty()){
        int f = q.front().first;
        int val = q.front().second;
        q.pop();
        if(dist[f] != -1) continue;
        dist[f] = val;
        for(int i=0; i<v[f].size(); i++){
            int next = v[f][i];
            q.push({next, val+1});
        }
    }
    int midx, mcnt, mval = -1;
    for(int i=1; i<=n; i++){
        if(mval < dist[i]){
            mval = dist[i];
            midx = i;
            mcnt = 0;
        }
        if(mval == dist[i]) mcnt++;
    }
    cout << midx << " " << mval << " " << mcnt;

    return 0;
}