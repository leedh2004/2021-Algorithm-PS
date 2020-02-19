#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

int chk[360];
vector<int> s; // 0~359 도달가능한 각도, 360 == 0

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> v(n); // 각도의 종류

    for(int i=0; i<n; i++){
        cin >> v[i];
        s.push_back(v[i]);
        chk[v[i]] = 1;
    }
    int before = 0;
    while(1){
        int temp = before;
        int size = s.size();
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                int p = s[i] + s[j] >= 360 ? s[i] + s[j] - 360 : s[i] + s[j];
                int m = s[i] - s[j] < 0 ? s[i] - s[j] + 360 : s[i] - s[j];
                if(!chk[p]){
                    before++; chk[p] = 1;
                    s.push_back(p);
                }
                if(!chk[m]){
                    before++; chk[m] = 1;
                    s.push_back(m);
                }
            }
        }
        if(temp == before) break;
    }

    while(k--){
        int temp;
        cin >> temp;
        if(chk[temp]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}