#include <cstdio>
#include <cmath>

int main()
{
    long long int c,k,p,ans=0;
    scanf("%lld%lld%lld",&c,&k,&p);
    for(int i=1;i<=c;i++)
    {
        ans=ans+k*i+p*i*i;
    }
    printf("%lld",ans);
    return 0;
}