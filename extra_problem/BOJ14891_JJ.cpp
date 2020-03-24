#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct tire
{
    int state[8];
    int val[3]; //up right left
};

tire t[5];
int k,num,dir;
vector<pair<int,int>> v; //돌려야하는 목록


//돌려주는 함수
void turn(int index,int direction)
{
    for(int i=0;i<3;i++) 
    {
        t[index].val[i] = t[index].val[i]-direction;
        if(t[index].val[i]>7)t[index].val[i]=0;
        if(t[index].val[i]<0)t[index].val[i]=7;
    }
    return ;
}

int main()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=0;j<8;j++) scanf("%1d",&t[i].state[j]);
        t[i].val[0]=0;
        t[i].val[1]=2;
        t[i].val[2]=6;
    }
    scanf("%d",&k);
    while (k--)
    {
        v.clear();
        scanf("%d%d",&num,&dir);
        v.push_back({num,dir});
        int dir1=dir;
        int dir2=dir;
       
        //왼쪽
        for(int i=num-1;i>0;i--)
        {
            if(dir1==1) dir1=-1;
            else dir1 = 1;
            //cout<<t[i].state[t[i].val[1]]<<"\n";
            //cout<< t[i+1].state[t[i+1].val[2]]<<"\n";
            if(t[i].state[t[i].val[1]] != t[i+1].state[t[i+1].val[2]]) 
            {
                v.push_back({i,dir1});
                //printf("%d turn\n",i);
                //turn(i,!(t[i+1].d));
            } 
            else break;
        }
        //오른쪽
        for(int j=num+1;j<=4;j++)
        {
            if(dir2==1) dir2=-1;
            else dir2 = 1;
            //cout<<t[j].state[t[j].val[2]]<<"\n";
            //cout<<t[j-1].state[t[j-1].val[1]]<<"\n";
            if( t[j].state[t[j].val[2]] != t[j-1].state[t[j-1].val[1]]) 
            {
                v.push_back({j,dir2});
                //printf("%d turn\n",j);
                //turn(j,!(t[j-1].d));
            }
            else break;
        }
        for(int i=0;i<v.size();i++) turn(v[i].first,v[i].second);
    }
    int ans=0;
    if(t[1].state[t[1].val[0]]==1) ans=ans+1;
    if(t[2].state[t[2].val[0]]==1) ans=ans+2;
    if(t[3].state[t[3].val[0]]==1) ans=ans+4;
    if(t[4].state[t[4].val[0]]==1) ans=ans+8;
    cout<<ans;
    return 0;
}