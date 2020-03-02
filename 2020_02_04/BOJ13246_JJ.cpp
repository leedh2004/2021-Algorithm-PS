#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n;
long long int b;
//b가 최대 100,000,000,000 인데 루트2를 씌우면 최대 316227정도
int sumdp[32000][6][6];
int powdp[32000][6][6];
int ans[6][6];


void solve(int pow_index,int sum_index)
{
    int temp;
    //ans행렬 0으로 초기화 현재 값은 sum_index에 저장되어 있음
    memset(ans,0,sizeof(ans));
    //곱셈
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            temp=sumdp[sum_index][i][k];
            for(int j=1;j<=n;j++)ans[i][j] = (ans[i][j]+temp*powdp[pow_index][k][j])%1000;
        }
    }
    //덧셈
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            ans[i][k]=(ans[i][k]+sumdp[pow_index][i][k])%1000;
        }
    }
}

void make_powdp()
{
    long long int pow_now=2;
    int pow_index=2;
    int tmp[6][6];
    int temp;
    while(1)
    {
        if(pow_now>b) break;
        memset(tmp,0,sizeof(tmp));    
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                temp=powdp[pow_index-1][i][k];
                for(int j=1;j<=n;j++) tmp[i][j]= (tmp[i][j]+temp*powdp[pow_index-1][k][j])%1000;
            }
        }
        memcpy(powdp[pow_index],tmp,sizeof(tmp));
        pow_index++;
        pow_now=pow_now*2;
    }
}

int main()
{
    scanf("%d%lld",&n,&b);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) 
        {
            scanf("%d",&sumdp[1][i][j]);
            powdp[1][i][j]=sumdp[1][i][j];
            ans[i][j]=sumdp[1][i][j];
        }
    }
    make_powdp();
    int now_index=1;
    long long int now=1;
    while(now<b)
    {
        if(now*2<=b)
        {
            solve(now_index,now_index);
            now=now*2;
            now_index++;
            memcpy(sumdp[now_index],ans,sizeof(ans));
        }
        else
        {
            long long int left = b-now;
            long long int left_now=1;
            int left_now_index=1;
            while(left_now*2<=left)
            {
                left_now=left_now*2;
                left_now_index++;
            }
            solve(left_now_index,now_index);
            now=now+left_now;
            now_index++;
            memcpy(sumdp[now_index],ans,sizeof(ans));
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}
