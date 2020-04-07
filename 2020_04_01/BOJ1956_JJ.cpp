#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int d[401][401];
int v,e;
int INF = 987654321;

void func()
{
   for(int i=1;i<=v;i++)
   {
       for(int j=1;j<=v;j++)
       {
           for(int k=1;k<=v;k++) if(d[i][j]>d[i][k]+d[k][j]) d[i][j] = d[i][k]+d[k][j];
       }
   }
}

int main()
{
    int st,ed,cost;
    scanf("%d%d",&v,&e);

    //초기화
    for(int i=1; i<=v;i++)
    {
        for(int j=1; j<=v;j++) d[i][j]= INF;
    }

    //엣지정보 입력받음
    for(int i=0;i<e;i++)
    {
        scanf("%d%d%d",&st,&ed,&cost);
        d[st][ed]=min(d[st][ed], cost);
    }
    func();
    bool flag = false;
    int ans  = INF;
    for(int i=1; i<=v;i++)
    {
        if(ans>d[i][i])
        {
            flag=true;
            ans = d[i][i];
        }
    }
    printf("%d\n", (flag)?ans:-1);
    return 0;
}