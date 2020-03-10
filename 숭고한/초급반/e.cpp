#include <iostream>
#include <cstdio>

using namespace  std;

int n,m,a,c=0;
int arr[1000];

int main()
{
    scanf("%d%d",&n,&m);
    a=n+1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        c=c+arr[i]+1;
    }
    int x=0;
    while((a*x+c)<m)x++;
    x--;
    //cout<<x<<"\n";

    long long int ans=0;
    ans = a*((x*(x+1)*(x*2+1))/6);
    m= m-((a*x)+c);
    long long int index=x+1;
    while (m!=0)
    {
        if(a<=m)
        {
            m=m-a;
            ans= ans+ index*index*a;
        }
        else
        {
            ans= ans+ index*index*m;
            m=0;
        }
        index++;
    }
    cout<<ans;
    return 0;
}