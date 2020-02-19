#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int order[501];
int adj[501][501]; // adj[y][x] edge y -> x
int indegree[501];

int main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        memset(adj, 0, sizeof(adj));
        memset(order, 0, sizeof(order));
        memset(indegree, 0, sizeof(indegree));
        int n; cin >> n;
        for(int i=1; i<=n; i++){
            cin >> order[i];
        }
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                adj[order[i]][order[j]] = 1;
                indegree[order[j]]++;
            }
        }
        int m; cin >> m;
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            if(adj[a][b]){ // a -> b 에서 b -> a 로 바꿔야 함.
                indegree[a]++;
                indegree[b]--;
            }else{
                indegree[b]++;
                indegree[a]--;
            }
            swap(adj[a][b], adj[b][a]);
        }
        queue<int> q;
        vector<int> ans;
        int f = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(indegree[j] == 0) q.push(j);
            }

            if(q.empty()){f = 1; break;}
            if(q.size() > 1){f=2; break;}

            int front = q.front();
            q.pop();
            ans.push_back(front);
            indegree[front] = -1;
            for(int k=1; k<=n; k++){
                if(adj[front][k]){
                    indegree[k]--;
                }
            }
        }
        if(f == 1) cout << "IMPOSSIBLE\n";
        else if (f == 2) cout << "?\n";
        else{
            for(auto v:ans) cout << v << " ";
            cout << endl;
        }
    }

    return 0;
}