#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int n,k,m,tmp;
int tree[4*4000000];
int arr[4000001];

int init(int index, int start, int end)
{
    int mid = (start+end)/2;
    if(start==end) tree[index]=arr[start];
    else tree[index] = max(init(index*2+1,start,mid),init(index*2+2,mid+1,end));
    //printf("index:%d value:%d start:%d end:%d\n",index,tree[index],start,end);
    return tree[index];
}

int find_and_update(int index, int start, int end, int value)
{
    if(start==end) 
    {
        tmp=tree[index];
        tree[index]=0;
        return tree[index];
    }
    int mid = (start+end)/2;
    if(tree[index*2+1]<=value) return tree[index]=max(tree[index*2+1], find_and_update(index*2+2,mid+1,end,value));
    else return tree[index]=max(tree[index*2+2], find_and_update(index*2+1,start,mid,value));
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++) scanf("%d",&arr[i]);
    sort(arr,arr+m);
    init(0,0,m-1);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&tmp);
        find_and_update(0,0,m-1,tmp);
        printf("%d\n",tmp);
    }
    return 0;
}