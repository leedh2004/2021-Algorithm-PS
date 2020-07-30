#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long int ll;
using namespace std;

vector<pair<int,pair<int,int> > > edges;
ll ans = 0;
int n,m;
int num_of_edges = 0;
int unionfind[100000];

int find(int node){
    if(unionfind[node] == node) return node;
    return unionfind[node] = find(unionfind[node]);
}
 
bool merge(int a, int b){
    int p_a = find(a);
    int p_b = find(b);
    if(p_a==p_b) return false;
    unionfind[p_a] = p_b;
    return true;
}

int main(){
    int st,ed,cost;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&st,&ed,&cost);
        edges.push_back(make_pair(cost,make_pair(st-1,ed-1)));
    }
    //cost가 낮은 순으로 정렬
    sort(edges.begin(),edges.end());

    //unionfind 설정
    for(int i=0;i<n;i++) unionfind[i] = i;

    for(int i=0;i<m;i++){
        //도시가 2개이기 때문에
        if(num_of_edges == n-2) break;

        if (merge(edges[i].second.first,edges[i].second.second)){
            ans = ans + edges[i].first;
            num_of_edges++;
        }
    }

    printf("%lld\n",ans);
    return 0;
}