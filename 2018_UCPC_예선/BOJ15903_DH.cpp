#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef unsigned long long ll;
priority_queue<ll, vector<ll>, greater<ll> > pq;
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        ll tmp; cin >> tmp;
        pq.push(tmp);
    }
    for(int i=0; i<m; i++){
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        pq.push(a+b);
        pq.push(a+b);
    }
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
    return 0;
}