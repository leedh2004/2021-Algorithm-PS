#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k,l;
int direction[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int tmpx,tmpy,tmp;
char tmpc;
int now_vector_index=0;

pair<int,int> front=make_pair(1,1);
pair<int,int> rear=make_pair(1,1);
pair<int,int> tmp_pair_front=make_pair(1,1);
pair<int,int> tmp_pair=make_pair(1,1);

struct rull{
    int t;
    char d;
};

vector <rull> v;

struct board{
    int val; //0:empty 1:apple 2:sneak
    int dir; //0:-> 2:<- 
};

board b[101][101];


int take_turn(int now_d, char turn_way)
{
    if(turn_way=='L') return (now_d+3)%4;
    else return (now_d+1)%4;
}

int is_done()
{
    if(front.first<1||front.first>n||front.second<1||front.second>n||b[front.first][front.second].val==2) return 1;
    else return 0;
}

void ppp()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cout<<b[i][j].val;
        cout<<"\n";
    }
    cout<<front.first<<" "<<front.second<<" "<<rear.first<<" "<<rear.second<<" \n";
}

int sneak_move()
{
    int total_time=0;
    while(1)
    {
        total_time++;
        tmp_pair_front.first=front.first;
        tmp_pair_front.second=front.second;
        front.first=tmp_pair_front.first+direction[b[tmp_pair_front.first][tmp_pair_front.second].dir][0];
        front.second=tmp_pair_front.second+direction[b[tmp_pair_front.first][tmp_pair_front.second].dir][1];
        //끝난경우
        if(is_done()) break;

        //사과를 먹지않은 경우
        if(b[front.first][front.second].val!=1)
        {
            b[rear.first][rear.second].val=0;
            tmp_pair.first=rear.first+direction[b[rear.first][rear.second].dir][0];
            tmp_pair.second=rear.second+direction[b[rear.first][rear.second].dir][1];
            rear.first=tmp_pair.first;
            rear.second=tmp_pair.second;
        }
        b[front.first][front.second].val=2;
        b[front.first][front.second].dir=b[tmp_pair_front.first][tmp_pair_front.second].dir;
        while(total_time==v[now_vector_index].t)
        {
            b[front.first][front.second].dir=take_turn(b[tmp_pair_front.first][tmp_pair_front.second].dir,v[now_vector_index].d);
            now_vector_index++;
        }
        //ppp();
    }
    return total_time;
}

bool cmp(const rull& a,const rull& b)
{
    if(a.t<b.t) return true;
    else return false;
}

int main()
{
    cin>>n>>k;
    b[1][1]={2,0};
    for(int i=1;i<=k;i++)
    {
        cin>>tmpx>>tmpy;
        b[tmpx][tmpy].val=1;
    }
    cin>>l;
    for(int i=1;i<=l;i++)
    {
        cin>>tmp>>tmpc;
        v.push_back({tmp,tmpc});
    }
    sort(v.begin(),v.end(),cmp);
    cout<<sneak_move();
    return 0;
}