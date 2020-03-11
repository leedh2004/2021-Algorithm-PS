#include <iostream>
#include <cstdio>

using namespace std;

int n,m,k;
long long int change_index,before_value,after_value;
long long int arr[1000001];
long long int tree[3000001];

//트리생성
long long int init(int index,int start, int end)
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

void update(int index,int start,int end)
{
    tree[index]=tree[index]+after_value-before_value;
    if(start==end) return ;

    int mid =(start+end)/2;
    if(change_index<=mid) update(index*2+1,start,mid);
    else update(index*2+2,mid+1,end);
}

int main()
{
    long long int s,e,val;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    init(0,0,n-1);
    for(int i=0;i<m+k;i++) 
    {
        scanf("%lld%lld%lld",&val,&s,&e);
        if(val==1)
        {
            change_index=s-1;
            before_value=sum(0 , 0 , n-1 ,s-1, s-1);
            after_value=e;
            //cout<<change_index<<before_value<<after_value<<"\n";
            update(0,0,n-1);
        } 
        if(val==2) printf("%lld\n",sum(0,0,n-1,s-1,e-1));
    }
    return 0;
}