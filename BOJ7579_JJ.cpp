#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N,C_data[101];
int sum_of_c=0;
long long int M,M_data[101];
long long int dp[101][10001]={0};

int dp_for_C()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=sum_of_c;j++)
        {
            if(j>=C_data[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-C_data[i]]+M_data[i]);
            else dp[i][j]=dp[i-1][j];
            //printf("dp[%d][%d] = %d\n",i ,j,dp[i][j]);
        }
    }
    for(int i=0;i<=sum_of_c;i++)
    {
        for(int j=0;j<=N;j++)
        {
            if(dp[j][i]>=M) return i;
        }
    }
}

int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++) cin>>M_data[i];
    for(int i=1;i<=N;i++) {
        cin>>C_data[i];
        sum_of_c=sum_of_c+C_data[i];
    }
    printf("%d",dp_for_C());
    return 0;
}

/*
int N;
long long int M;
struct mypair{long long int m,c;};
mypair data[101];

int greedy()
{
    long long int sum_of_c=0;
    long long int sum_of_m=0;
    int tmp=1;
    while(sum_of_m<M)
    {
        //printf("%lld\n",sum_of_c);
        sum_of_c = data[tmp].c+sum_of_c;
        sum_of_m = data[tmp].m+sum_of_m;
        tmp++;
    }
    return sum_of_c;
}

bool cmp(const mypair& a,const mypair& b)
{
    if(a.c==0 || b.c==0)
    {
        if(a.c==0 && b.c==0) return a.m>b.m;
        if(a.c==0) return true;
        if(b.c==0) return false;
    }
    return (a.m/a.c)>(b.m/b.c);
}


int main()
{
    cin >>N>>M;
    for(int i=1;i<=N;i++) cin>>data[i].m;
    for(int i=1;i<=N;i++) cin>>data[i].c;
    sort(data+1,data+N+1,cmp);
    //for(int i=1;i<=N;i++) printf("%lld \t %lld\n",data[i].m,data[i].c);
    printf("%d",greedy());
}
*/