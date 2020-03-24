#include <iostream>
#include <cstdio>
#include <cmath>


using namespace std;

int main()
{
    long long int n,m;
    int m_list[10001];
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d",&m_list[i]);
    long long int sum=0,mid,t=0,k=0;

    if(n<=m)
    {
        printf("%d",n);
        return 0;
    }

    //이분탐색
    long long int start=0,end=20000000000;
    while (start<=end)
    {
        mid = (start+end)/2;
        sum=0;
        for(int i=1;i<=m;i++) sum=sum+(mid/m_list[i])+1;
        //printf("%lld %lld %lld\n ",start,end,sum);
        if(sum>n) end=mid-1;
        else
        {
            start=mid+1;
            t=max(t,mid);
            k=max(k,sum);
        }      
    }
    //printf("%lld\n%lld\n",t,k);
    if(k==n)
    {
        int last;
        int val=30;
        for(int i=1;i<=m;i++) {
            if(t%m_list[i]<=val)
            {
                val=t%m_list[i];
                last=i;
            }
        }
        printf("%d",last);
        return 0;
    }
    else
    {
        t++;
        for(int i=1;i<=m;i++) 
        {
            if(t%m_list[i]==0) k++;
            if(k==n) 
            {
                printf("%d",i);
                return 0;
            }
        }
    }
    return 0;
}