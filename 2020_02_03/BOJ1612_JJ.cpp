#include <iostream>
using namespace std;
int n,k=0,ans=0;
int main()
{
    cin>>n;
    if(n%2&&n%5)
    {
        while(1) {
            k=(k*10+1)%n;
            ans++;
            if(k==0) break;
        }
        cout<<ans;
        return 0;
    }
    cout<<"-1";
    return 0;
}