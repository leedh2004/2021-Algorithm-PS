#include <iostream>
#include <string>
using namespace std;

int main(){

    string l, r;
    cin >> l >> r;
    int ans = 0;
    if(l.size() == r.size()){
        for(int i=0; i<l.size(); i++){
            if(l[i] == r[i]){
                if(l[i] == '8') ans++;
                else continue;
            } 
            else break;
        }
    }
    cout << ans;
    return 0;
}