#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int r,c,m;
int now=0;
int total=0;
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
struct shark
{
    int x,y,s,d,z;
};

int table[101][101];

shark shark_tmp;
vector<shark> v;
int tmp;


void shark_move()
{
    for(int i=0;i<v.size();i++)
    {
        memcpy(&shark_tmp,&v[i],sizeof(shark_tmp));
        if(shark_tmp.d==1||shark_tmp.d==2)
        {
            shark_tmp.s=shark_tmp.s%(2*(r-1));
            while(shark_tmp.s>0)
            {
                if(shark_tmp.x==1) shark_tmp.d=2;
                if(shark_tmp.x==r) shark_tmp.d=1;
                shark_tmp.x=shark_tmp.x+dir[shark_tmp.d-1][0];
                shark_tmp.s--;
            }
            shark_tmp.s=v[i].s;
        }
        else
        {
            shark_tmp.s=shark_tmp.s%(2*(c-1));
            while(shark_tmp.s>0)
            {
                if(shark_tmp.y==1) shark_tmp.d=3;
                if(shark_tmp.y==c) shark_tmp.d=4;
                shark_tmp.y=shark_tmp.y+dir[shark_tmp.d-1][1];
                shark_tmp.s--;
            }
            shark_tmp.s=v[i].s;
        }
        memcpy(&v[i],&shark_tmp,sizeof(shark_tmp));
        if(table[v[i].x][v[i].y]==-1) table[v[i].x][v[i].y]=i;
        else //존재하는경우
        {
            if(v[i].z>v[table[v[i].x][v[i].y]].z)
            {
                v.erase(v.begin()+table[v[i].x][v[i].y]);
                table[v[i].x][v[i].y]=--i;
            }
            else
            {
                v.erase(v.begin()+i);
                i--;
            }
        }
    }
}

//정렬시 낚시꾼이 잡아야하는 물고기가 0번째에 배치됨
bool cmp(const shark& a,const shark& b)
{
    if(abs(now-a.y)<abs(now-b.y)) return true;
    else if(a.y==b.y&&a.x<b.x) return true;
    else return false;
}

int main()
{
    //input
    cin>>r>>c>>m;
    for(int i=0;i<m;i++) {
        cin>>shark_tmp.x>>shark_tmp.y>>shark_tmp.s>>shark_tmp.d>>shark_tmp.z;
        v.push_back(shark_tmp);
        table[v[i].x][v[i].y]=i;
    }

    //start to move
    for(int i=0;i<c;i++)
    {
        //no fish
        if(v.size()==0)
        {
            cout<<total;
            return 0;
        }

        //now -> standard of sort
        now++;
        sort(v.begin(),v.end(),cmp);
        if(v[0].y==now)
        {
            total=total+v[0].z;
            v.erase(v.begin());
        }
        memset(table,-1,sizeof(table));
        shark_move();
    }    
    cout<<total;
    return 0;
}