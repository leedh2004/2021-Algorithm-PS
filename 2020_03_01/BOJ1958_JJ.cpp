#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

string str[3];
int lcs[101][101][101];
int size[3];

int main()
{
    cin>>str[0]>>str[1]>>str[2];
    for(int i=0;i<=2;i++) str[i]=" "+str[i];
    for(int i=0;i<=2;i++) size[i]=str[i].size();
    for(int i=0;i<size[0];i++)
    {
        for(int j=0;j<size[1];j++)
        {
            for(int k=0;k<size[2];k++)
            {
                if(i==0 || j==0 || k==0) lcs[i][j][k]=0;
                else if(str[0][i]==str[1][j] && str[1][j]==str[2][k]) lcs[i][j][k]= lcs[i-1][j-1][k-1]+1;
                else lcs[i][j][k]= max(lcs[i][j][k-1] , max(lcs[i-1][j][k],lcs[i][j-1][k] ));
            }
        }
    }
    cout<<lcs[size[0]-1][size[1]-1][size[2]-1];
    return 0;
}