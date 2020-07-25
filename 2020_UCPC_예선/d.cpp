#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;
int n;


vector<int> adj[300001];
vector<int> adj_one_way[300001];
bool visited[300001];
ll D_num=0;
ll G_num=0;


// 단방향 트리만들기
void make_one_way(int node){
    visited[node] = true;
    for(int i=0;i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
            adj_one_way[node].push_back(adj[node][i]);
            make_one_way(adj[node][i]);
        }
    }
}

// 문제해결
void solve(int node){
    // D-tree : 해당노드의 자식들의 자식들의 수의 합 
    // G-tree : 
    for(int i=0;i<adj_one_way[node].size();i++){
        int child_index = adj_one_way[node][i];
        for(int j=0;j<adj_one_way[child_index].size();j++){
            int child_child_index = adj_one_way[child_index][j];
            D_num = D_num + adj_one_way[child_child_index].size();   
        }
        G_num = G_num + (adj_one_way[child_index].size() * (adj_one_way[child_index].size()-1)) / 2;
    }
    for(int i=0;i<adj_one_way[node].size();i++) solve(adj_one_way[node][i]);
}

int main(){
    int a,b,root_index;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size()==1) {
            root_index = i;
            break;
        } 
    }
    make_one_way(root_index);
    // cout<<"\n";
    solve(root_index);
    // cout<<D_num<<G_num<<"\n";
    if(D_num > G_num*3) cout<<"D"<<"\n";
    else if(D_num <G_num*3) cout<<"G"<<"\n";
    else{
        cout<<"DUDUDUNGA\n";
    }
    return 0;
}