#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <stack>
#include <cstring>
using namespace std;

int n,m;
int arr[9][9];
int visited[9][9];
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int virus_size = 0;
int wall_size = 0;
int safe_size = 0;

stack <pair<int,int> > s;
vector <pair <int,int> > v;
vector <int> comb;

int inside(int i,int j)
{
    return (0<i&&i<=n) &&(0<j&&j<=m);
}

int dfs(int x,int y)
{
    int size_v=1;
    s.push({x,y});
    //cout<<"-------------------\n"<<"start  "<<x<<" "<<y<<"\n";
    while(!s.empty())
    {
        pair <int,int> p={s.top().first,s.top().second};
        s.pop();
        for(int i=0;i<4;i++)
        {
            pair <int,int> p_tmp={p.first+d[i][0],p.second+d[i][1]};
            if(inside(p_tmp.first,p_tmp.second)&&(arr[p_tmp.first][p_tmp.second]==0)&&!visited[p_tmp.first][p_tmp.second])
            {
                //cout<<p_tmp.first<<" "<<p_tmp.second<<"\n";
                visited[p_tmp.first][p_tmp.second]=1;
                s.push(p_tmp);
                size_v++;
            }
        }
    }
    //cout<<"in dts"<<size_v<<'\n';
    return size_v;
}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) {
            cin>>arr[i][j];
            if(arr[i][j]==0) {
                v.push_back({i,j});
                comb.push_back(0);
            }
            else if(arr[i][j]==1) wall_size++;
        }
    }
    comb[0]=1;
    comb[1]=1;
    comb[2]=1;
    //fill_n(&comb[0],&comb[2],1);
   // memset(comb.begin(),1,3);
    sort(comb.begin(),comb.end());

    do{
        vector <pair <int,int> > p;
        memset(visited,0,sizeof(visited));
        virus_size=0;
        for(int i=0;i<comb.size();i++)
        {
            if(comb[i]==1) {
                //cout<<i<<" ";
                p.push_back({v[i].first,v[i].second});
                arr[v[i].first][v[i].second]=1;
            }
        }
        //cout<<'\n';
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if((arr[i][j]==2)&&(visited[i][j]==0)) {
                    virus_size=virus_size+dfs(i,j);
                    //cout<<virus_size<<"\n";
                }
            }
        }
        safe_size=max(safe_size,n*m-(wall_size+3)-virus_size);
        for(int i=0;i<3;i++) arr[p[i].first][p[i].second]=0;
    }while(next_permutation(comb.begin(),comb.end()));
    cout<<safe_size;
    return 0;
}