#include <iostream>

using namespace std;

int t,n,start_x,start_y,end_x,end_y;
int x,y,r;
int ans;


int is_in(int i,int j,int x,int y,int r)
{
    return (i-x)*(i-x)+(j-y)*(j-y) < r*r;
}

int main()
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>start_x>>start_y>>end_x>>end_y>>n;
        ans=0;
        for(int j=0;j<n;j++)
        {
            cin>>x>>y>>r;
            if(is_in(start_x,start_y,x,y,r)!=is_in(end_x,end_y,x,y,r)) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}