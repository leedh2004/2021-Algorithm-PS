#include <iostream>
#include <cstdio>

//ios::sync_with_stdio(false);

using namespace std;

int N,M,S,E,tmp,N_list[2001]={0};
int dp[2001][2001]={0};

void palindrome_dp()
{
    for(int i=3;i<=N;i++) //i가 사이즈가 된다
    {   
        for(int j=1;j<=N-i+1;j++) //몇개의 집합이 있는가?
        {
            tmp =j+i-1;
            if(dp[j+1][tmp-1]==1 && N_list[j]==N_list[tmp]) dp[j][tmp]=1;
        }
    }
}



int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&N_list[i]);
    for(int i=1;i<=N;i++) dp[i][i]=1;
    for(int i=1;i<N;i++) 
    {
        if(N_list[i]==N_list[i+1]) dp[i][i+1] = 1;
        else dp[i][i+1] = 0;
    }
    palindrome_dp();
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&S,&E);
        printf("%d\n",dp[S][E]);
    }
    return 0;
}