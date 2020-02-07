#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
long long int ans=0;
long long int arr[300001];
long long int max_v=-1;
long long int check=0;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%lld",&arr[i]);
        arr[i]=-arr[i];
    }
    sort(&arr[1],&arr[n+1]);
    max_v=1-arr[1];
    for(int i=1;i<=n;i++)
    {
        if(max_v<=n-arr[i]) ans=i;
        max_v=max(max_v,i-arr[i]);
    }
    printf("%lld",ans);
    return 0;
}