#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string n;
int sum[5001];
int len;
int mod=1000000;

void solv()
{
    for(int i=1;i<n.size();i++)
    {
        if(n[i]-'0'>=1) sum[i]=(sum[i]+sum[i-1])%mod;
        int tmp = (n[i-1]-'0')*10+(n[i]-'0');
        if(10<=tmp&&tmp<=26) sum[i]=(sum[i]+sum[i-2])%mod;
    }
}

int main()
{
    cin>>n;
    n=' '+n;
    sum[0]=1;
    solv();
    cout<<sum[n.size()-1];
    return 0;
}