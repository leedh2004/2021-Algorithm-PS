#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

vector<int> v[300001];
bool visited[300001];
int indegree[300001];

ll d; // ㄷ
ll j; // ㅈ

void dfs(int here, int chk){
    if(chk == 4){
        d++;
    }
    int size = v[here].size();
    for(int i=0; i<size; i++){
        int next = v[here][i];
        if(!visited[next]){
            visited[next] = 1;
            dfs(next, chk+1);
            visited[next] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        indegree[a]++;
        indegree[b]++;
    }

    for(int i=1; i<=n; i++){
        // visited[i] = 1;
        // dfs(i, 1);
        // visited[i] = 0;
        ll val = indegree[i];
         j += val * (val-1) * (val-2) / 6;
        int size = v[i].size();
        for(int j=0; j<size; j++){
            ll next = v[i][j];
            ll a = indegree[i];
            ll b = indegree[next];
            if( a >= 2 && b >= 2){
                d += (a-1) * (b-1);
            }
        }
    }
    
    d /= 2;
    j *= 3;
    //cout << d << " " << j;
    if (d > j){
        cout << "D";
    }else if(d < j){
        cout << "G";
    }else{
        cout << "DUDUDUNGA";
    }
    return 0;
}