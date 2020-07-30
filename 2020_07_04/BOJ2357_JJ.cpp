#include <cstdio>
#include <vector>

#define mid ((begin+end)>>1)
#define l_node (node<<1)
#define r_node (l_node+1)
#define INF 0x7fffffff

typedef long long ll;

using namespace std;

struct MaxSegmentTree {
    vector<ll> arr, tree;
    
    MaxSegmentTree(int size) {
        arr.resize(size);
        tree.resize(size<<2);
    }
    
    ll init(int node, int begin, int end) {
        if (begin == end) return tree[node] = arr[begin];
        ll l = init(l_node, begin, mid);
        ll r = init(r_node, mid+1, end);
        return tree[node] = l>r?l:r;
    }
    
    ll update(int node, int begin, int end, int pos, ll val) {
        if (pos < begin || end < pos) return tree[node];
        if (begin == end) return tree[node] = val;
        ll l = update(l_node, begin, mid, pos, val);
        ll r = update(r_node, mid+1, end, pos, val);
        return tree[node] = l>r?l:r;
    }
    
    ll query(int node, int begin, int end, int l_pos, int r_pos) {
        if (r_pos < begin || end < l_pos) return 0;
        if (l_pos <= begin && end <= r_pos) return tree[node];
        ll l = query(l_node, begin, mid, l_pos, r_pos);
        ll r = query(r_node, mid+1, end, l_pos, r_pos);
        return l>r?l:r;
    }
};

struct MinSegmentTree {
    vector<ll> arr, tree;
    
    MinSegmentTree(int size) {
        arr.resize(size);
        tree.resize(size<<2);
    }
    
    ll init(int node, int begin, int end) {
        if (begin == end) return tree[node] = arr[begin];
        ll l = init(l_node, begin, mid);
        ll r = init(r_node, mid+1, end);
        return tree[node] = l<r?l:r;
    }
    
    ll update(int node, int begin, int end, int pos, ll val) {
        if (pos < begin || end < pos) return tree[node];
        if (begin == end) return tree[node] = val;
        ll l = update(l_node, begin, mid, pos, val);
        ll r = update(r_node, mid+1, end, pos, val);
        return tree[node] = l<r?l:r;
    }
    
    ll query(int node, int begin, int end, int l_pos, int r_pos) {
        if (r_pos < begin || end < l_pos) return INF;
        if (l_pos <= begin && end <= r_pos) return tree[node];
        ll l = query(l_node, begin, mid, l_pos, r_pos);
        ll r = query(r_node, mid+1, end, l_pos, r_pos);
        return l<r?l:r;
    }
};

int main() {
    
    int N,M;
    scanf("%d%d", &N, &M);
    
    MinSegmentTree min_seg(N);
    MaxSegmentTree max_seg(N);
    
    for (int i = 0; i < N; ++i) {
        ll tmp;
        scanf("%lld", &tmp);
        min_seg.arr[i] = tmp;
        max_seg.arr[i] = tmp;
    }
    min_seg.init(1, 0, N-1);
    max_seg.init(1, 0, N-1);

    while(M--)
    {
        int st,ed;
        scanf("%d%d",&st,&ed);
        printf("%lld %lld\n", min_seg.query(1,0,N-1,st-1,ed-1),max_seg.query(1,0,N-1,st-1,ed-1));
    }
    return 0;
}
