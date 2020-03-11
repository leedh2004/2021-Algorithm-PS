#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long int n;
long long int a[500001];
long long int b[500001];
long long int ans[500001];


int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<n;i++) scanf("%lld",&b[i]);
    ans[n-1]=0;
    long long int* index;
    for(int i=0;i<n-1;i++)
    {
        index = upper_bound(b,b+(n-1),a[i]);
        if( *index>a[i]) index--;
        //cout<<index-b<<" "<<a[i]<<" "<<*index<<"\n";
        if(i<(index-b)) ans[i]=(index-b)-i;
        else ans[i]=0;
    }
    for(int i=0;i<n;i++) printf("%lld ",ans[i]);
    return 0;
}
