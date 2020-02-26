#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n % 2 == 0 ||  n % 5 == 0){
        cout << -1;
    }else{
        int one = 1;
        int cnt = 1;
        while(one % n){
            one %= n;
            one *= 10;
            one++;
            cnt++;
        }
        cout << cnt;
    }
    return 0;
}