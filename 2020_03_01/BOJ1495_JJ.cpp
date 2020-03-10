#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

int n,s,m,val;
bool check[101][1001];

int main()
{
    cin>>n>>s>>m;
    memset(check,false,sizeof(check));
    check[0][s]=true;
    bool flag =false;
    for(int i=1;i<=n;i++)
    {
        cin>>val;
        flag=false;
        for(int j=0;j<=m;j++)
        {
            if(check[i-1][j]==true)
            {
                if(m>=j+val)
                {
                    flag=true;
                    check[i][j+val] =true;
                }
                if(0<=j-val)
                {
                    flag=true;
                    check[i][j-val] =true;
                }
            }
        }
        if(!flag) 
        {
            cout<<"-1";
            return 0;
        }
    }
    for(int i=m;i>=0;i--)
    {
        if(check[n][i]==true)
        {
            cout<<i;
            return 0;
        }
    }
}