#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n,m,k,a,b,c,total,l,r,before,after;
int arr[1000001];
const int MOD = 1000000007;
long long int tree[1000001*4];
int max__tree_index=0;

long long int init(int index , int start , int end)
{
    int mid = (start+end)/2;
    if(start==end) tree[index] = arr[start];
    else tree[index] = ( init(index*2+1,start,mid)%MOD * init(index*2+2,mid+1,end)%MOD )%MOD;
    max__tree_index=(max__tree_index,index);
    return tree[index];
}

long long int p(int index, int start, int end)
{
    //구하려는 구간 left ~ right
    //현재 탐색구간 start ~ end

    //case 1 현재탐색구간이 구하려는 구간에 포함되는 경우
    if(l<=start && end<=r) return tree[index];
    //case2 아예 포함이 안되는 경우
    else if (start>r || end<l) return 1;
    int mid = (start+end)/2;
    return ( p(index*2+1,start,mid)%MOD * p(index*2+2,mid+1,end)%MOD )%MOD;
}

long long int update(int index, int start, int end)
{
    if(start==end && end==before) tree[index]=after;
    else 
    {
        int mid = (start+end)/2;
        if(mid<before) tree[index]= ( tree[index*2+1] * update(index*2+2,mid+1,end) % MOD ) % MOD;
        else tree[index] = (update(index*2+1,start,mid)%MOD *tree[index*2+2] ) % MOD;
    }
    return tree[index];
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    init(0,0,n-1);
    total=m+k;
    for(int i=1;i<=total;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a==1)
        {
            before=b-1;
            after=c;
            update(0,0,n-1);
        }
        else 
        {
            l=b-1;
            r=c-1;
            printf("%lld\n",p(0,0,n-1));
        }
    }
    return 0;
}