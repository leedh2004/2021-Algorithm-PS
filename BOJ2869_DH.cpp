#include <iostream>
using namespace std;
int main(){
    int a, b, v;
    cin >> a >> b >> v;
    //하루에 a - b 미터 올라감.
    v = v - a;
    if(v <= 0) cout << "1";
    else {
        if(v % (a-b) == 0) cout << v / (a - b) + 1;
        else cout << (v / (a - b)) + 2;
    }
    return 0;
}