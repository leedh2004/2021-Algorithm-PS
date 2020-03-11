#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

long long int n;
long long int tmp;

vector<long long int> v;


int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&tmp);
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(long long int i=0;i<n+1;i++)
    {
        if( (i+1)!=v[i] ) 
        {
            cout<<(i+1);
            return 0;
        }
    }
    return 0;
}