#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int r,c,m;
int left_to_move;
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int table[101][101];

struct shark{
    int x,y,s,d,z;
    bool is_live={true};
};

shark tmp;
vector <shark> v;

void shark_move()
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].is_live==false) continue;
        left_to_move=v[i].s;
        if(v[i].d==1||v[i].d==2)
        {
            left_to_move=left_to_move%((r-1)*2);
            while(left_to_move)
            {
                if((v[i].d==1)&&(v[i].x==1)) v[i].d=2;
                if((v[i].d==2)&&(v[i].x==r)) v[i].d=1;
                v[i].x=v[i].x+dir[v[i].d-1][0];
                left_to_move--;
            }
        }
        else if(v[i].d==3||v[i].d==4)
        {
            left_to_move=left_to_move%((c-1)*2);
            while(left_to_move)
            {
                if((v[i].d==4)&&(v[i].y==1)) v[i].d=3;
                if((v[i].d==3)&&(v[i].y==c)) v[i].d=4;
                v[i].y=v[i].y+dir[v[i].d-1][1];
                left_to_move--;
            }
        }
        if(table[v[i].x][v[i].y]==-1) table[v[i].x][v[i].y]=i;
        else //한칸에 상어가 2마리 들어간 경우
        {
            if(v[table[v[i].x][v[i].y]].z>v[i].z) v[i].is_live=false;
            else {
                v[table[v[i].x][v[i].y]].is_live=false;
                table[v[i].x][v[i].y]=i;
            }
        }
    }
}

void ppp()
{
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++) 
        {
            if(table[i][j]==-1) cout<<"-1 ";
            else cout<<v[table[i][j]].z<<" ";
        }
        cout<<"\n";
    }

}

int main()
{
    int ans=0;
    cin>>r>>c>>m;
    for(int i=0;i<m;i++)
    {
        cin>>tmp.x>>tmp.y>>tmp.s>>tmp.d>>tmp.z;
        tmp.is_live=true;
        v.push_back(tmp);
    }
    for(int i=1;i<=c;i++)
    {
        int next_catch_shark=-1;
        int next_catch_shark_r=r+1;
        //낚시
        for(int j=0;j<v.size();j++)
        {
            if(v[j].is_live==false) continue;
            if((i==v[j].y)&&(next_catch_shark_r>v[j].x))
            {
                next_catch_shark=j;
                next_catch_shark_r=v[j].x;
            }
        }
        if(next_catch_shark!=-1)
        {
            //cout<<"get shark :"<<v[next_catch_shark].z<<"\n";
            ans=ans+v[next_catch_shark].z;
            v[next_catch_shark].is_live=false;
        }
        memset(table,-1,sizeof(table));
        shark_move();
        //ppp();
        //cout<<"------------\n";
    }
    cout<<ans;
    return 0;
}


/*

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
                if(shark_tmp.x==1&&shark_tmp.d==1) shark_tmp.d=2;
                if(shark_tmp.x==r&&shark_tmp.d==2) shark_tmp.d=1;
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
                if(shark_tmp.y==1&&shark_tmp.d==4) shark_tmp.d=3;
                if(shark_tmp.y==c&&shark_tmp.d==3) shark_tmp.d=4;
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

void ppp()
{
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++) cout<<table[i][j]<<" ";
        cout<<"\n";
    }

}

//정렬시 낚시꾼이 잡아야하는 물고기가 0번째에 배치됨
bool cmp(const shark& a,const shark& b)
{
    if(abs(now-a.y)<abs(now-b.y)) return true;
    else if((a.y==b.y)&&(a.x<b.x)) return true;
    else return false;
}

int main()
{
    //input
    cin>>r>>c>>m;
    for(int i=0;i<m;i++) {
        cin>>shark_tmp.x>>shark_tmp.y>>shark_tmp.s>>shark_tmp.d>>shark_tmp.z;
        v.push_back(shark_tmp);
        //table[v[i].x][v[i].y]=i;
    }

    //no fish
    if(v.size()==0)
    {
        cout<<total;
        return 0;
    }

    //start to move
    for(int i=1;i<=c;i++)
    {
        //now -> standard of sort
        now=i;
        sort(v.begin(),v.end(),cmp);
        if(v[0].y==now)
        {
            cout<<"get shark :"<<v[0].z<<"\n";
            total=total+v[0].z;
            v.erase(v.begin());
        }
        memset(table,-1,sizeof(table));
        shark_move();
        ppp();
        cout<<"----------------------\n";
    }    
    cout<<total;
    return 0;
}
*/