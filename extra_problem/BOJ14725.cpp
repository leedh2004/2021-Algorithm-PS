#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef struct Node{
    map<string, Node> child;
}Node;

Node root;

void insertVector(Node &v, vector<string> &str, int idx){
    if(idx == str.size()) return;
    string s = str[idx];
    if (v.child.find(s) == v.child.end()){
        v.child[str[idx]] = Node();
    }
    insertVector(v.child[str[idx]], str, idx + 1);
}

void dfs(Node &v, int depth){
    for(auto i : v.child){
        for(int j=0; j<depth; j++) cout << "--";
        cout << i.first << '\n';
        dfs(i.second, depth+1);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        vector<string> v;
        for(int j=0; j<k; j++){
            string s;
            cin >> s;
            v.push_back(s);
        }
        insertVector(root, v, 0);
    }
    dfs(root, 0);
    return 0;
}