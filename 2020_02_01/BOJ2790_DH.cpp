#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m = 0;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int cnt = 1, i; 
    for(i = n - 1; i >= 0; i--){
        m = max(m, v[i] + cnt++);
    }
    for(i = 0; i <= n-1; i++){
        if(v[i] + n >= m) break;    
    }
    cout << n - i;
    return 0;
}