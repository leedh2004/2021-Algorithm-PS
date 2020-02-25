#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

int n;
long long int b;

struct s{
    long long int p;
    int h[6][6];
};
vector<s> v;
s now;

void cal(int index)
{
    int tmp[6][6];
    now.p=now.p+v[index].p;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) 
        {
            int sum=0;
            for(int k=1;k<=n;k++) sum=sum+(now.h[i][k]*v[index].h[k][j])%1000;
            tmp[i][j]=sum%1000;
        }
    }
    memcpy(now.h,tmp,sizeof(tmp));
}

int main()
{
    cin>>n>>b;
    now.p=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) 
        {
            cin>>now.h[i][j];
            if(now.h[i][j]==1000) now.h[i][j]=0;
        }

    }
    v.push_back(now);
    while(now.p!=b)
    {
        if(now.p*2<=b)
        {
            cal(v.size()-1);
            v.push_back(now);
        }
        else
        {
            for(int i=v.size()-1;i>=0;i--)
            {
                if( (b-now.p)>=v[i].p )
                {
                    cal(i);
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cout<<now.h[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
