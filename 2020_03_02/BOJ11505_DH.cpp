#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

#define MOD 1000000007

ll tree[4000000];
vector<int> v;

ll init(int node, int start, int end){
    if(start == end) return tree[node] = v[start];
    int mid = ( start + end ) / 2;
    tree[node] = ( (init(node*2, start, mid))%MOD * (init(node*2+1, mid+1, end))%MOD ) % MOD; 
    return tree[node];
}

ll query(int node, int start, int end, int a, int b){ // a~b까지의 곱을 구함.
    if( b < start || end < a ) return 1;
    if( a <= start && end <= b ){
        return tree[node];
    }else{
        int mid = (start + end) / 2;
        return ( (query(node*2, start, mid, a, b)%MOD) * (query(node*2+1, mid+1, end, a, b)%MOD) ) % MOD; 
    }
}

ll update(int node, int start, int end, int b, int c){ // b번째 노드를 c로 갱신
    if( start <= b && b <= end){
        int mid = (start + end) / 2;
        if(start != end){
            return tree[node] = ( (update(node*2, start, mid, b, c)%MOD) * (update(node*2+1, mid+1, end, b, c)%MOD) ) % MOD;
        }else{
            return tree[node] = c;
        }
    }else
        return tree[node];
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    v.resize(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    init(1, 0, n-1);
    for(int i=0; i<m+k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        b--;
        if(a == 1){ // b번째 수를 c로 바꿈
            update(1, 0, n-1, b, c);
            v[b] = c;
        }else{ // b부터 c까지의 곱
            c--;
            cout << query(1, 0, n-1, b, c) << '\n';
        }
    }
    
    return 0;
}