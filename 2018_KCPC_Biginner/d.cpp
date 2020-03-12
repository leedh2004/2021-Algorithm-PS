#include <iostream>

using namespace std;

long long int now=11;
long long int goal;
long long int ans=1;
int main()
{
    cin>>goal;
    while (now<=goal)
    {
        now=now*10+1;
        ans++;
    }
    cout<<ans;
}