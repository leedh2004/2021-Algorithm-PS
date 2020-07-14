#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;
vector<int> v[500001];
vector<int> child[500001]; // child만 담는다.
bool visited[500001];
ll ans = 0;

void dfs(int here){
    visited[here] = 1;
    for(int i=0; i<v[here].size(); i++){
        int next = v[here][i];
        if(!visited[next]){
            child[here].push_back(v[here][i]);
            dfs(v[here][i]);
        }
    }
}

void sum(int here, int depth){
    if(child[here].size() == 0){
        ans += depth;
        return;
    }
    for(int i=0; i<child[here].size(); i++){
        int c = child[here][i];
        sum(c, depth+1);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    sum(1, 0);
    if(ans%2 == 1){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}