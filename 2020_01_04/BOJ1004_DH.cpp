#include <iostream>
#include <cmath>
using namespace std;

int distance(int a, int b, int x, int y){
    return pow((a-x), 2) + pow((b-y), 2);
}

int main(){
    int y, x, y2, x2;
    int t;
    cin >> t;
    while(t--){
        cin >> x >> y >> x2 >> y2;
        int k;
        cin >> k;
        int ans = 0;
        while(k--){
            int a, b, r;
            cin >> a >> b >> r;
            int c = 0;
            if ( distance(a, b, x, y) <= pow(r, 2) ) c++;
            if ( distance(a, b, x2, y2) <= pow(r, 2) )c++;
            if (c == 1) ans++; // 원이 하나만 포함할경우
        }

        cout << ans << endl;
    }


    return 0;
}