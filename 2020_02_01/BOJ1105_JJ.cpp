#include <iostream>
#include <string>

using namespace std;

string  l,r;
int ans=0;

int main()
{
    cin>>l>>r;
    if(l.length()==r.length())
    {
        for(int i=0;i<l.length();i++)
        {
            if(l[i]==r[i])
            {
                if(l[i]=='8') ans++;
            }
            else break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}