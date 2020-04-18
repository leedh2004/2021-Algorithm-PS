#include <iostream>
using namespace std;
int main(){
    int n, f;
    cin >> n >> f;
    n = n / 100;
    n = n * 100;
    while(n){
        if(n % f == 0){
            if(n%100 < 10) cout << "0";
            cout << n % 100;
            return 0;
        }
        n++;
    }
    return 0;
}