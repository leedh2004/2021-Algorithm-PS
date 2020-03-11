#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
long long int arr[1000000];
long long int tree[1000000];

//트리생성
int init(int index,int start, int end)
{
    if(start==end) tree[index] = arr[start];
    else tree[index] = init(index*2+1,start,(start+end)/2) + init(index*2+2,(start+end)/2+1,end);
    return tree[index];
}

long long int sum(int index,int start,int end,int left,int right)
{
    //start ~ end 탐색 구간
    //letf ~ right 구하려는 합 구간 
    
    //안겹치는 경우
    if(right<start || end<left) return 0;
    //포함하는 경우
    else if(left<=start&&end<=right) return tree[index];
    int mid = (start+end)/2;
    //그 외의 경우
    return sum(index*2+1,start,mid,left,right) + sum(index*2+2,mid+1,end,left,right);
}

int main()
{
    int s,e;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    init(0,0,n-1);
    for(int i=0;i<m;i++) 
    {
        scanf("%d%d",&s,&e);
        printf("%lld\n",sum(0,0,n-1,s-1,e-1));
    }
    return 0;
}