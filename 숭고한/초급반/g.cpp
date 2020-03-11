#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

bool ck[2000002];
bool sosu_ck[2000002];
queue<int> q;
vector<int> v;
int now,next,s,e,sz,ans=0;;

bool is_sosu(int x)
{
    if(sosu_ck[x]==true) return true;
    bool r =true;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0) 
        {
            r=false;
            break;
        }
    }
    return r;
}

int main()
{
    int t;scanf("%d",&t);
    memset(sosu_ck,false,sizeof(ck));
    while(t--)
    {
        scanf("%d%d%d",&now,&s,&e);
        memset(ck,false,sizeof(ck));
        ans=0;
        bool flag = true;
        bool flag2 =false;
        for(int i=s;i<=e;i++) {
            sosu_ck[i]=is_sosu(i);
            //printf("%d ",sosu_ck[i]);
            if(flag&&sosu_ck[i]) flag=false;
        }

        if(flag) 
        {
            printf("-1\n");
            continue;
        }

        q.push(now);
        ck[now]=true;
        while(!q.empty())
        {
            if(flag2) break;
            sz = q.size();
            while(sz--)
            {
                now=q.front();
                q.pop();
                if( s<=now && now<=e && sosu_ck[now])
                {
                    printf("%d\n",ans);
                    flag2=true;
                    while(!q.empty()) q.pop();
                    break;
                }
                if(!ck[now+1]) 
                {
                    q.push(now+1);
                    ck[now+1]=true;
                }
                if(now>0 && !ck[now-1])
                {
                    q.push(now-1);
                    ck[now-1] = true;
                }
                if(!ck[now/2])
                {
                    q.push(now/2);
                    ck[now/2] = true;
                }
                if(!ck[now/3])
                {
                    q.push(now/3);
                    ck[now/3] = true;
                }
            }
            ans++;
        }

    }
}