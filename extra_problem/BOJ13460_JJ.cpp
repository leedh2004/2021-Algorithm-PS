#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct S
{
    int rx;
    int ry;
    int bx;
    int by;
};

int n,m;
//상하좌우 - 0 1 2 3
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char arr[12][12];
pair <int, int> h;
queue <S> q;
struct S first,next;
int red=0;
int blue=0;

/*
val이 1일때 달라지는게 없다,파란공이 들어갔다. -> 해당 가지를 끊어야한다
val이 -1일때 구멍에 파란공이 들어왔다. -> 해당 가지를 끊어야한다
val이 2일때 구멍에 빨간공이 들어왔다. -> 종료
*/
int val=0;

//두개의 지점이 같은 좌표값을
int same_place(S X,S Y)
{
    if( ((X.rx==Y.rx)&& (X.ry==Y.ry)) &&( (X.bx==Y.bx) && (X.by==Y.by) ) ) return 1;
    else return 0;
}

//true red is front at the direction
//false blue is front or same at the direction
bool who_is_first(S state, int dir)
{
    if (dir==0) return state.rx<state.bx;
    else if(dir==1) return state.bx<state.rx;
    else if(dir==2) return state.ry<state.by;
    else if(dir==3) return state.by<state.ry;
}


S check(S o,int d)
{
    S now;
    memcpy(&now,&o,sizeof(S));
    bool red_is_first=who_is_first(o,d);
    red=0;
    blue=0;
    if(red_is_first==true)
    {
        //move red
        while(arr[now.rx+dir[d][0]][now.ry+dir[d][1]]!='#')
        {
            now.rx=now.rx+dir[d][0];
            now.ry=now.ry+dir[d][1];
            if((now.rx==h.first)&&(now.ry==h.second)) red=1;
        }
        //move blue
        while(arr[now.bx+dir[d][0]][now.by+dir[d][1]]!='#')
        {
            if((now.bx+dir[d][0]==now.rx)&&(now.by+dir[d][1]==now.ry)) {
                //파랑공과 빨간공이 둘다 들어간 경우
                if((now.rx==h.first)&&(now.ry==h.second)) blue=1;
                else break;
            }
            now.bx=now.bx+dir[d][0];
            now.by=now.by+dir[d][1];
            if((now.bx==h.first&&now.by==h.second)) blue=1;
        }
    }
    else
    {
        //move blue
        while(arr[now.bx+dir[d][0]][now.by+dir[d][1]]!='#')
        {
            now.bx=now.bx+dir[d][0];
            now.by=now.by+dir[d][1];
            if((now.bx==h.first)&&(now.by==h.second)) blue=1;
        }
        //move red
        while(arr[now.rx+dir[d][0]][now.ry+dir[d][1]]!='#')
        {
            if((now.rx+dir[d][0]==now.bx)&&(now.ry+dir[d][1]==now.by)) 
            {
                //파랑공과 빨간공이 둘다 들어간 경우
                if((now.bx==h.first)&&(now.by==h.second)) red=1;
                else break;
            }
            now.rx=now.rx+dir[d][0];
            now.ry=now.ry+dir[d][1];
            if((now.rx==h.first)&&(now.ry==h.second)) red=1;
        }
    }
    //빨간공만 들어간 경우
    if ((red==1)&&(blue==0)) val=2;
    //파란공이 들어간 경우(빨간공의 성공여부와 상관없음)
    else if(blue==1) val=-1;
    //주어진 좌표와 옮겨진 좌표가 같은경우
    else if(same_place(now,o)==1) val=1;
    //큐에 들어가야하는 좌표
    else val =0;
    return now;
}

/* for Debuging
void print(S k)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i][j]=='#') cout<<arr[i][j];
            else if(arr[i][j]=='O') cout<<arr[i][j];
            else if(k.rx==i &&k.ry==j) cout<<"R";
            else if(k.bx==i &&k.by==j) cout<<"B";
            else cout<<'.';
        }
        cout<<"\n";
    }
    cout<<"\n";
}
*/

int bfs()
{
    int stage =0;
    q.push(first);
    while((!q.empty())&&(stage<10))
    {
        int qs = q.size();
        for(int i=0;i<qs;i++)
        {
            S tmp=q.front();
            q.pop();
            for(int j=0;j<4;j++)
            {
                S tmp2 = check(tmp,j);
                if(val==0) q.push(tmp2);
                else if(val==2) return stage+1;
            }
            //cout<<"---------------------------------\n";
        }
        stage=stage+1;
    }
    return -1;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) 
        {
            cin>>arr[i][j];
            if (arr[i][j]=='R')
            {
                first.rx=i;
                first.ry=j;
            }
            else if(arr[i][j]=='B')
            {
                first.bx=i;
                first.by=j;
            }
            else if(arr[i][j]=='O') 
            {
                h.first = i;
                h.second = j;
            }
            
        }
    }
    printf("%d",bfs());
    return 0;
}