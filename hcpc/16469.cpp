#include <iostream>
#include <cstdio>
#include <climits>
#include <queue>
#include <cstring>

using namespace std;

int rc_table[101][101];
int ans_table[3][101][101];
bool rc_check_table[3][101][101];
pair<int,int> swings[3];
int r,c;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
queue< pair<int,int>> q;

bool is_in(int x,int y)
{
    return ((0<x&&x<=r) && (0<y&&y<=c)) ;
}

int find_max(int a,int b,int c)
{
    return max(max(a,b),c);
}


void bfs(int index)
{
    memset(rc_check_table,false,sizeof(rc_check_table));
    int x,y,tmpx,tmpy,sz;
    while(!q.empty()) q.pop();
    q.push(swings[index]);
    rc_check_table[index][swings[index].first][swings[index].second]=true;
    ans_table[index][swings[index].first][swings[index].second]=0;
    int now_d=1;
    while(!q.empty())
    {
        sz=q.size();
        for(int i=0;i<sz;i++)
        {
            x=q.front().first;
            y=q.front().second;
            q.pop();
            //cout<<x<<" "<<y<<"\n";
            //cout<<"-------tmp--------\n";
            for(int j=0;j<4;j++)
            {
                tmpx=x+dir[j][0];
                tmpy=y+dir[j][1];
                //cout<<tmpx<<" "<<tmpy<<"\n";
                //cout<<rc_check_table[index][tmpx][tmpy]<<"\n";
                //cout<<rc_table[tmpx][tmpy]<<"\n";
                if(is_in(tmpx,tmpy) && rc_check_table[index][tmpx][tmpy]==false && rc_table[tmpx][tmpy]==0)
                {
                    q.push({tmpx,tmpy});
                    rc_check_table[index][tmpx][tmpy]=true;
                    ans_table[index][tmpx][tmpy]=now_d;
                }
            }
        }
        //cout<<"-------end--------\n";
        now_d++;
    }
}

void p(int index)
{
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)cout<<ans_table[index][i][j]<<" ";
        cout<<"\n";
    }
    cout<<"----------------\n";
}

void solve()
{   
    int ans=INT_MAX;
    int t,count;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(ans_table[0][i][j]!=-1 && ans_table[1][i][j]!=-1&&ans_table[2][i][j]!=-1)
            {
                t=find_max(ans_table[0][i][j],ans_table[1][i][j],ans_table[2][i][j]);
                if(ans>t) 
                {
                    ans=t;
                    count=1;
                }
                else if (ans==t) count++;
            }
        }
    }
    if(ans==INT_MAX) cout<<"-1";
    else cout<<ans<<"\n"<<count;
}

int main()
{
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)scanf("%1d",&rc_table[i][j]);
    }
    for(int i=0;i<3;i++) scanf("%d%d",&swings[i].first,&swings[i].second);
    memset(ans_table,-1,sizeof(ans_table));
    for(int i=0;i<3;i++) bfs(i);
    //for(int i=0;i<3;i++) p(i);
    solve();
    return 0;
}