#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;
int n;


vector<int> adj[300001];
int degree[300001];
bool visited[300001];
ll D_num=0;
ll G_num=0;


// 단방향 트리만들기
void solve(int node){
    visited[node] = true;
    G_num = G_num + (degree[node] * (degree[node]-1)* (degree[node]-2)) / 6;
    for(int i=0;i<degree[node];i++){
        int child_index = adj[node][i];

        if(degree[child_index]==1) continue;

        // cout<<"child_index : "<<child_index<<"\n";
        for(int j=0;j<degree[child_index];j++){
            int child_child_index = adj[child_index][j];
            if(node == child_child_index) continue;
            // cout<<"child_child_index : "<<child_child_index<<"\n";
            // cout<<"child_child_index size : "<<adj[child_child_index].size()<<"\n";
            if(degree[child_child_index]>1) D_num = D_num + (degree[child_child_index]-1);   
        }
    }
    for(int i=0;i<degree[node];i++) {
        if(!visited[adj[node][i]]) solve(adj[node][i]);
    }
}


int main(){
    int a,b;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++) degree[i]= adj[i].size();
    solve(1);
    D_num = D_num/2;
    G_num = G_num*3;
    // cout<<D_num<<" "<<G_num<<"\n";
    if(D_num > G_num) cout<<"D"<<"\n";
    else if(D_num <G_num) cout<<"G"<<"\n";
    else{
        cout<<"DUDUDUNGA\n";
    }
    return 0;
}