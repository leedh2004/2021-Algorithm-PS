#include <iostream>
using namespace std;

typedef struct Node {
    Node* next[10];
    bool end = false;
}Node;

Node * root;

bool addString(Node* node, string s, int idx, int len, bool created){
    if (len == idx) {
        if(!created) return false;
        else {
            node->end = true;
            return true;
        }
    }
    int val = s[idx] - '0'; // 추가할 값.
    if (node->next[val]){
        if(node->next[val]->end) return false; // 존재함
        return addString(node->next[val], s, idx+1, len, 0);
    }else{
        node->next[val] = new Node();
        return addString(node->next[val], s, idx+1, len, 1);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        root = new Node(); // init
        bool flag = true;
        for(int i=0; i<n; i++){
            string s; cin >> s;
            int len = s.size();
            if(!addString(root, s, 0, len, 1)){
                flag = false;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}