#include <iostream>
#include <cmath>

using namespace std;

int min_d=360;
int n,k,tmp;
int n_arr[11];

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>n_arr[i];
    n_arr[0]=360;
    while(1)
    {
        int before_min_d=min_d;
        for(int i=0;i<=n;i++)
        {
            if(n_arr[i]%min_d!=0)
            {
                min_d=min(n_arr[i]%min_d,min_d);
            }
        }
        if(before_min_d==min_d) break;
    }
    //cout<<min_d<<"\n";
    for(int j=1;j<=k;j++)
    {
        cin>>tmp;
        if(tmp%min_d==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

