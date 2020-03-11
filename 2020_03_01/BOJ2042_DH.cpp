#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll tree[4000000];
int n, m, k;
ll seq[1000001];

void init(int node, int s, int e){
    if(s == e) tree[node] = seq[s];
    else{
        init(node*2, s, (s + e) / 2);
        init(node*2+1, (s + e) / 2 + 1, e);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

ll query(int node, int s, int e, int i, int j){
    if ( e < i || s > j) return 0;
    if ( s >= i && e <= j ){
        return tree[node];
    }
    else return query(node*2, s, (s + e)/2, i, j) + query(node*2+1, (s+e)/2+1, e, i, j);
}

void update(int node, int s, int e, int i, ll diff){
    if(i < s || i > e) return;
    tree[node] += diff;
    if (s != e) {
        update(node*2, s, (s+e)/2, i, diff);
        update(node*2+1, (s+e)/2+1, e, i, diff);
    }
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //cin >> n >> m >> k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=n; i++)
        scanf("%lld", &seq[i]);
    init(1, 1, n);

    for(int i=0; i<m+k; i++){
        int a, b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        if(a == 1){
            ll diff = c - seq[b];
            seq[b] = c;
            update(1, 1, n, b, diff);
        }else if(a==2) {
            printf("%lld\n", query(1, 1, n, b, c));
            //cout << query(1, 1, n, b, c) << '\n'; 
        }
    }

    return 0;
}