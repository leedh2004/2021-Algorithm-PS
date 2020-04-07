#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int a[10001];
int p[10001];
int visited[10001];

int getParent(int a){
    if(p[a] == a) return a;
    else return getParent(p[a]);
}

void Union(int c, int d) {
    int pa = getParent(c);
    int pb = getParent(d);
    if( a[pa] < a[pb] ) p[pb] = pa; // 친구비 작은쪽이 아빠다.
    else p[pa] = pb;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        p[i] = i;
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        Union(a, b);
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        int parent = getParent(i);
        if(!visited[parent]){
            ans += a[parent];
            visited[parent] = 1;
        }
    }
    ans <= k ? cout << ans : cout << "Oh no";
    return 0;
}