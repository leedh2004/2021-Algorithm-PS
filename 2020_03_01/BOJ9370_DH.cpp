#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 987654321;

int main(){

    int T; cin >> T;
    while(T--){
        int n, m, t; cin >> n >> m >> t;
        int s, g, h; cin >> s >> g >> h; // s에서 ?까지 최단거리를 구할 때 g와 h를 경유하는 ?를 찾아야 한다.
        vector<pair<int, int> > v[2001]; // 간선 정보
        for(int i=0; i<m; i++){
            int a, b, d; cin >> a >> b >> d;
            v[a].push_back({-d, b}); // priority_queue를 이용하기 위해 음수 값을 저장
            v[b].push_back({-d, a});
        }
        int candidate[100]; // 목적지 후보
        for(int i=0; i<t; i++)
            cin >> candidate[i];
        int d[2001], gd[2001], hd[2001];
        for(int i=1; i<=n; i++) d[i] = gd[i] = hd[i] = INF; // 최단거리를 담는 배열
        d[s] = 0;
        gd[g] = 0;
        hd[h] = 0;
        priority_queue<pair<int, pair<int, int> > > pq;
        for(int i=0; i<v[s].size(); i++) pq.push({v[s][i].first, { s, v[s][i].second}}); // 시작점과 연결된 간선을 넣는다.
        while(!pq.empty()){
            int dist = - pq.top().first; // 양수로 거리를 받는다.
            int here = pq.top().second.first;
            int next = pq.top().second.second;
            pq.pop();
            if(d[next] > d[here] + dist){
                d[next] = d[here] + dist;
                for(int i=0; i<v[next].size(); i++) pq.push({v[next][i].first, { next, v[next][i].second}}); // 다음 점과 연결된 간선을 넣는다.
            } 
        }
        // for(int i=1; i<=n; i++){
        //     cout << "d[" << i << "]: " << d[i] << endl;
        // }
        for(int i=0; i<v[g].size(); i++) pq.push({v[g][i].first, { g, v[g][i].second}}); // 시작점과 연결된 간선을 넣는다.
        while(!pq.empty()){
            int dist = - pq.top().first; // 양수로 거리를 받는다.
            int here = pq.top().second.first;
            int next = pq.top().second.second;
            pq.pop();
            if(gd[next] > gd[here] + dist){
                gd[next] = gd[here] + dist;
                for(int i=0; i<v[next].size(); i++) pq.push({v[next][i].first, { next, v[next][i].second}}); // 다음 점과 연결된 간선을 넣는다.
            } 
        }
        // for(int i=1; i<=n; i++){
        //     cout << "gd[" << i << "]: " << gd[i] << endl;
        // }
        for(int i=0; i<v[h].size(); i++) pq.push({v[h][i].first, { h, v[h][i].second}}); // 시작점과 연결된 간선을 넣는다.
        while(!pq.empty()){
            int dist = - pq.top().first; // 양수로 거리를 받는다.
            int here = pq.top().second.first;
            int next = pq.top().second.second;
            pq.pop();
            if(hd[next] > hd[here] + dist){
                hd[next] = hd[here] + dist;
                for(int i=0; i<v[next].size(); i++) pq.push({v[next][i].first, { next, v[next][i].second}}); // 다음 점과 연결된 간선을 넣는다.
            } 
        }
        // for(int i=1; i<=n; i++){
        //     cout << "hd[" << i << "]: " << hd[i] << endl;
        // }
        // d[?] == d[h] + hd[g] + gd[?] or d[g] + gd[h] + hd[?] 라면 ans에 추가
        vector<int> ans;
        for(int i=0; i<t; i++){
            int c = candidate[i];
            //cout << "c: " << c << " " << d[c] << " " << d[h]+hd[g]+gd[c] << " "<< d[h]+gd[h]+hd[c] << endl;
            
            if (d[c] == d[h]+hd[g]+gd[c] || d[c] == d[g]+gd[h]+hd[c]){
                //cout << "ans push " << c << endl;
                ans.push_back(c);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}