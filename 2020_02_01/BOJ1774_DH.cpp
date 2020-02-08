#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;
typedef long long ll;

int p[100001];
pair<ll, ll> arr[100001]; // first: x, second: y

priority_queue<pair<double, pair<int,int> >> pq; // 거리와 좌표를 담는다.

int getParent(int a){
    if ( p[a] == a ) return a;
    else return p[a] = getParent(p[a]);
}

double findDist(int a, int b){
    return -sqrt(pow(abs(arr[a].first - arr[b].first), 2) + pow(abs(arr[a].second - arr[b].second), 2)); // 음수로 리턴 
}

bool pluss(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if ( a != b ){
        p[a] < p[b] ? p[b] = p[a] : p[a] = p[b];
        return true;
    } 
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        p[i] = i; // 부모 초기화
        cin >> arr[i].first >> arr[i].second;
    }
    
    int cnt = 0;

    while(m--){
        int a, b;
        cin >> a >> b;
        pluss(a, b);
    }

    double ans = 0.00;

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int c = getParent(i); int d =getParent(j);
            pq.push({findDist(i, j),{i, j}}); // i번째와 j번째의 거리간선 추가 
        }
    }

    while(!pq.empty()){
        double d = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
        a = getParent(a);
        b = getParent(b);
        if(pluss(a, b)) ans -= d;
    }

    cout << fixed;
    cout.precision(2);
    //printf("%.2lf", ans);
    cout << ans;
    return 0;
}