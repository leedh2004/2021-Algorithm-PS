#include <iostream>
using namespace std;

int ans[14] = {-1, -2, 2, 1, -3, -4, 2, 1, -5, -6, 2, 1, -1, -2};

int main(){

    int n, mod;
    cin >> n;
    n--;
    mod = n % 14;
    n = n / 14;
    if(ans[mod] < 0){
        int v = ans[mod];
        if(v == -1) cout << "baby";
        if(v == -2) cout << "sukhwan";
        if(v == -3) cout << "very";
        if(v == -4) cout << "cute";
        if(v == -5) cout << "in";
        if(v == -6) cout << "bed";
    }else{
        int v = ans[mod];
        v += n;
        cout << "tu";
        if(v >= 5){
            cout << "+ru*" << v;
        }else{
            while(v--){
                cout << "ru";
            }
        }
    }
    return 0;
}
// 다익스트라, 벨만포드, 크루스칼, 플로이드와샬
// 네트워크 플로우, KMP+트라이, Segment Tree