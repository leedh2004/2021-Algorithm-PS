#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string x, y;
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    string xy = to_string(stoi(x)+stoi(y));
    reverse(xy.begin(), xy.end());
    cout << stoi(xy);
    return 0;
}