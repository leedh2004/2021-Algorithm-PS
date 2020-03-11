#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n;
int bonus=0;
int ans=0;
string str;

int main()
{
    cin>>n>>str;
    str=" "+str;
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='O')
        {
            ans=ans+i;
            ans=ans+bonus;
            bonus++;
        }
        else
        {
            bonus=0;
        }
        //cout<<ans<<"\n";

    }
    cout<<ans;
    return 0;
}