#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int board[51][51];

int parent[251];

int getParent(int a){
    if(parent[a] == a) return a;
    else return parent[a] = getParent(parent[a]);
}

void Union(int a, int b){
    if(parent[a] < parent[b]) parent[a] = b;
    else parent[b] = parent[a];
}

int main(){
    int n, m;
    cin >> n >> m;
    int cnt = 2;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char a; cin >> a;
            if(a == '1') board[i][j] = -1; // -1은 못감
            if(a == 'S') board[i][j] = 1; // 시작지점
            if(a == 'K') board[i][j] = cnt++; // 복제지점
        }
    }
    // 각 지점에서 지점까지의 edge를 pq에 넣어야 한다.
    priority_queue<pair<int, pair<int, int> > > pq;

    while(cnt>0){
        cnt--;
        parent[cnt] = cnt;
        if(cnt == 0) break;
        //우선 cnt가 있는곳의 좌표를 구한다.
        int y, x;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (board[i][j] == cnt){
                    y = i; x = j;
                }
            }
        }

        int dist[51][51];
        memset(dist, -1, sizeof(dist));
        queue<pair<int, pair<int, int> > > q;
        q.push({0, {y, x}});

        while(!q.empty()){
            int val = q.front().first;
            int y = q.front().second.first;
            int x = q.front().second.second;
            q.pop();
            if(dist[y][x] != -1) continue;
            dist[y][x] = val;
            if(board[y][x] > 0 && board[y][x] != cnt){
                pq.push({-val, {cnt, board[y][x]}});
            }
            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny >= 0 && nx >= 0 && ny < n && nx < n && board[ny][nx] != -1){
                    q.push({val+1, {ny, nx}});
                }
            }
        }
    }
    int ans = 0;
    int tmp = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
        int pa = getParent(a);
        int pb = getParent(b);
        if( pa == pb) continue;
        ans += cost;
        tmp++;
        Union(pa, pb);
    }
    if(tmp == m) cout << ans;
    else cout << -1;
    return 0;
}