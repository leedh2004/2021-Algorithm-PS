#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector <int> adj[401];
int n,k,s;
bool ck[401];
bool pos[401][401];

void bfs()
{
    queue<int> q;
    int now,next;
    for(int i=1;i<=n;i++)
    {
        while (!q.empty()) q.pop();
        memset(ck,false,sizeof(ck));
        q.push(i);
        ck[i]=true;
        while (!q.empty())
        {
            now=q.front();
            q.pop();
            for(int j=0;j<adj[now].size();j++)
            {
                next=adj[now][j];
                if(!ck[next])
                {
                    ck[next]=true;
                    pos[i][next]=true;
                    q.push(next);
                }
            }
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" : ";
        for(int j=1;j<=n;j++)
        {
            cout<<pos[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    
    return ;
}

int main()
{
    int st,ed;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&st,&ed);
        adj[st].push_back(ed);
    }
    bfs();
    scanf("%d",&s);
    for(int i=1;i<=s;i++)
    {
        scanf("%d%d",&st,&ed);
        if(pos[st][ed]&&(!pos[ed][st])) printf("-1\n");
        else if (pos[ed][st]&&(!pos[st][ed])) printf("1\n");
        else printf("0\n");
    }
    return 0;
}   