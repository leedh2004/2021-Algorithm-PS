#include <iostream>
#include <queue>

using namespace std;

const int INF = 987654321;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(){
    int t = 1;
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        int a[130][130];
        int dist[130][130];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> a[i][j];
                dist[i][j] = INF;
            }
        }
        //존나 BFS인데?
        queue<pair<int, pair<int, int> > > q;
        q.push({a[0][0], {0, 0}});
        while(!q.empty()){
            int val = q.front().first;
            int y = q.front().second.first;
            int x = q.front().second.second;
            q.pop();
            if(val < dist[y][x]){
                dist[y][x] = val;
                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n){
                        q.push({a[ny][nx] + val, {ny, nx}});
                    }
                }
            }
        }
        cout << "Problem " << t << ": " << dist[n-1][n-1] << '\n';
        t++;
    }
    return 0;
}