#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long int ans=0;
long long int n;
int jusawe[6];

int max_1=0;
int min_1=50;
int min_2=100;
int min_3=150;

//c[0]-a
int c[6]={5,4,3,2,1,0};

int main()
{
    cin>>n;
    for(int i=0;i<6;i++) cin>>jusawe[i];
    for(int i=0;i<6;i++)
    {
        max_1=max(max_1,jusawe[i]);
        min_1=min(min_1,jusawe[i]);
        for(int j=0;j<6;j++)
        {
            if(i==j || c[i]==j) continue;
            min_2=min(min_2,jusawe[i]+jusawe[j]);
            for(int k=0;k<6;k++)
            {
                if(k==i || k==j || c[i]==k||c[j]==k) continue;
                min_3=min(min_3,jusawe[i]+jusawe[j]+jusawe[k]);
            }
        }
    }
    if(n==1)
    {
        for(int i=0;i<6;i++)ans=ans+jusawe[i];
        ans=ans-max_1;
    }
    else ans = min_3*4 + min_2*(n-1)*4 +min_2*(n-2)*4+ min_1*(n-2)*(n-2) + min_1*(n-2)*(n-1)*4;
    cout<< ans;
    return 0;
}