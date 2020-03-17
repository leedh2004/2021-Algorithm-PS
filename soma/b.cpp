#include <iostream>
#include <cstring>

using namespace std;

int t,n,m,ans;
int table[51][51];

int main()
{
		cin.tie(NULL);
		ios_base::sync_with_stdio(false);
   	cin>>t;
    while (t--)
    {
				//cout<<"start\n";
        cin>>n>>m;
        memset(table,0,sizeof(table));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>table[i][j];
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(table[i][j]&&table[i+1][j+1]&&table[i+1][j]&&table[i][j+1])
                {
                    table[i][j]=2;
                    table[i+1][j+1]=2;
                    table[i][j+1]=2;
                    table[i+1][j]=2;
                }
            }
        }
        bool flag = false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(table[i][j]==1) flag=true;
            }
        }
				if(flag) cout<<"NO"<<"\n";
				else cout<<"YES"<<"\n";
    }
    return 0;
}