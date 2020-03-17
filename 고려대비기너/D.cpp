#include <iostream>
#include <string>
using namespace std;

int cnt[10];

int main(){

    int ans = 1;    
    
    int val = 11;
    int n;
    cin >> n;

    while(val <= n){
        ans++;
        val = val * 10; val ++;
    }

    cout << ans;
    return 0;
}