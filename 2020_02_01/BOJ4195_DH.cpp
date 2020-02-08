#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, string> m; // key : 이름, value : 부모
unordered_map<string, int> numOfNetwork; // key : 부모이름, value : 이 네트워크의 수

string getParent(string a){
    if(m.find(a) == m.end()){ // 처음의 인풋
        m[a] = a; // 부모는 자기자신
        numOfNetwork[a] = 1; // 네트워크 수는 1명
        return a;
    }
    if (m[a] == a) return a;
    else return m[a] = getParent(m[a]);
}

string union_parent(string a, string b){
    a = getParent(a);
    b = getParent(b);
    if( a == b ) { return a;} // 부모가 같으면 합칠 필요가 없음.
    else{
        string newParent = a > b ? b : a;
        string oldParent = a > b ? a : b;
        numOfNetwork[newParent] += numOfNetwork[oldParent];
        m[oldParent] = newParent;
        return newParent;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int f;
        m.clear();
        cin >> f;
        for(int i=0; i<f; i++){
            string a, b;
            cin >> a >> b;
            cout << numOfNetwork[union_parent(a, b)] << '\n';
        }
    }

    return 0;
}