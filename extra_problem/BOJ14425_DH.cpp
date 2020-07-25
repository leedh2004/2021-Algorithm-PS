#include <iostream>
#include <map>

using namespace std;
int ans = 0;

struct Node{
    //map<char, Node> child;
    Node *child[26];
    bool end = false;
};

Node *root;

void insertNode(Node *node, string &s, int idx){
    if(s.size() == idx) return;
    if( node->child[s[idx]-'a'] == NULL ){
        node->child[s[idx]-'a'] = new Node();
    }
    if(idx == s.size() - 1) node->child[s[idx]-'a']->end = true;
    insertNode(node->child[s[idx]-'a'], s, idx+1);
}

void findNode(Node *node, string &s, int idx){
    if(s.size() == idx && node->end){
        ans++;
        return;
    }
    if(node->child[s[idx]-'a'] == NULL){
        //cout << s << ": not has " << s[idx];
        return;
    }
    findNode(node->child[s[idx]-'a'], s, idx+1);
}

int main(){
    int n, m;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    root = new Node();
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        insertNode(root, s, 0);
    }
    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        findNode(root, s, 0);
    }
    cout << ans;
    return 0;
}