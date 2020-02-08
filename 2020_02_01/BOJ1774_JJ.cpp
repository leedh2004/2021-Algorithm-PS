#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct edge
{
    int start;
    int end;
    double d;
};

vector<edge> e;

struct god
{
    long long int x,y;
    int parent;
};

god god_arr[1004];

int n,m;
int cnt=0;


int get_parent(int x)
{
    if(god_arr[x].parent==x) return x;
    return god_arr[x].parent=get_parent(god_arr[x].parent);
}

bool same_group(int x,int y)
{
    x=get_parent(x);
    y=get_parent(y);
    return x==y?true:false;
}

void be_same_parent(int x,int y)
{
    x=get_parent(x);
    y=get_parent(y);
    if(x!=y) god_arr[y].parent=x;
}

bool compare(const edge& a, const edge& b)
{
    if(a.d<b.d) return true;
    else return false;
}

int main()
{
    long long int x,y;
    int tmpx,tmpy;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
    {
        scanf("%lld%lld",&x,&y);
        god_arr[i]={x,y,i};
        if(i>1)
        {
            //간선 만들기
            for(int j=1;j<i;j++) 
            {
                double tmp= sqrt(pow(god_arr[j].x - god_arr[i].x,2)+pow(god_arr[j].y - god_arr[i].y,2));
                e.push_back({j,i,tmp});
            }
        }
    }

    sort(e.begin(),e.end(),compare);

    //이미 연결된 간선 입력
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&tmpx,&tmpy);
        if(same_group(tmpx,tmpy)) continue;
        be_same_parent(tmpx,tmpy);
        cnt++;
    }

    double ans=0;
    for(int i=0;i<e.size();i++)
    {
        //cout<<"("<<god_arr[e[i].start].x<<","<<god_arr[e[i].start].y<<") "<<" ("<<god_arr[e[i].end].x<<","<<god_arr[e[i].end].y<<")  d: "<<e[i].d<<"\n";
        //이미 연결되어있다면 건너뛰기
        if(same_group(e[i].start,e[i].end)) continue;
        
        //연결
        be_same_parent(e[i].start,e[i].end);
        cnt++;
        ans=ans+e[i].d;

        //전부 연결되었는지 확인
        if(cnt==n-1)
        {
            printf("%.2lf",ans);
            return 0;
        }
    }
    //cout<<"0";
    return 0;
}