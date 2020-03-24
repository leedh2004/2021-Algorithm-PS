#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n,l;
int table[101][101];
bool check1[101][101];
bool check2[101][101];

int solve()
{
    int ans=0;
    //행
    for(int i=1;i<=n;i++)
    {
        bool flag =true; 
        for(int j=1;j<n;j++) 
        {
            //앞에가 더 큰경우
            if(table[i][j]>table[i][j+1])
            {
                //범위를 벗어난 경우
                if(j+l>n) flag= false;
                else
                {
                    for(int k=1;k<=l;k++)
                    {
                        if( (table[i][j]-1 !=table[i][j+k]) || check1[i][j+k]) flag=false;
                        check1[i][j+k]=true;
                    }
                }
            }
            else if (table[i][j]<table[i][j+1])
            {
                if(j<l) flag=false;
                else
                {
                    for(int k=0;k<l;k++)
                    {
                        if( (table[i][j+1]-1 !=table[i][j-k]) || check1[i][j-k]) flag=false;
                        check1[i][j-k]=true;
                    }
                }
            }
        }
        if(flag) ans++;
        //if(flag) printf("%d HANG \n",i);
    }
    //열
     for(int i=1;i<=n;i++)
    {
        bool flag =true; 
        for(int j=1;j<n;j++) 
        {
            //앞에가 더 큰경우
            if(table[j][i]>table[j+1][i])
            {
                //범위를 벗어난 경우
                if(j+l>n) flag= false;
                else
                {
                    for(int k=1;k<=l;k++)
                    {
                        if( (table[j][i]-1 !=table[j+k][i]) || check2[j+k][i]) flag=false;
                        check2[j+k][i]=true;
                    }
                }
            }
            else if (table[j][i]<table[j+1][i])
            {
                if(j<l) flag=false;
                else
                {
                    for(int k=0;k<l;k++)
                    {
                        if( (table[j+1][i]-1 !=table[j-k][i]) || check2[j-k][i] ) flag=false;
                        check2[j-k][i]=true;
                    }
                }
            }
        }
        if(flag) ans++;
        //if(flag) printf("%d Y \n",i);
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) scanf("%d",&table[i][j]);
    }
    printf("%d",solve());
    return 0;
}