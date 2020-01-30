#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int n,m,first_city,tmp;
int c[1001][1001];
int plan[1001];
int check[1001];

void bfs()
{
    q.push(first_city);
    check[first_city]=1;
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(check[i]==0&&c[tmp][i]==1)
            {
                q.push(i);
                check[i]=1;
            }
        }
    }
}

void ppp()
{
    tmp=0;
    for(int i=1;i<=n;i++)
    {
        if(plan[i]==1&&check[i]==0) tmp=1;
    }
    if(tmp==1) cout<<"NO";
    else cout<<"YES";
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>c[i][j];
    }
    cin>>tmp;
    first_city=tmp;
    plan[tmp]=1;
    for(int i=2;i<=m;i++) {
        cin>>tmp;
        plan[tmp]=1;
    }
    bfs();
    ppp();
    return 0;
}