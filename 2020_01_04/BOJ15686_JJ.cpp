#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <numeric>
#include <cstring>

using namespace std;

int n,m,tmp;
int ans=INT_MAX;

struct p
{
    int x,y;
};

vector<p> house;
vector<p> chicken_house;
vector<int> activate_ck_house;

int d[101][14];
int chicken_d[101];


void cal_each_d()
{
    memset(d,-1,sizeof(d));
    fill_n(chicken_d,house.size(),INT_MAX);
    for(int i=0;i<house.size();i++)
    {
        for(int j=0;j<chicken_house.size();j++)
        {
            if(activate_ck_house[j]==1)
            {
                d[i][j]=abs(house[i].x-chicken_house[j].x)+abs(house[i].y-chicken_house[j].y);
                chicken_d[i] = min(chicken_d[i],d[i][j]);
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>tmp;
            if(tmp==1) house.push_back({i,j});
            else if(tmp==2) 
            {
                chicken_house.push_back({i,j});
                activate_ck_house.push_back(0);
            }
        }
    }

    //for combination
    for(int i=0;i<m;i++) activate_ck_house[i]=1;
    sort(activate_ck_house.begin(),activate_ck_house.end());

    do
    {
        cal_each_d();
        ans=min(accumulate(chicken_d,chicken_d+house.size(),0),ans);
    }while(next_permutation(activate_ck_house.begin(),activate_ck_house.end()));
    cout<<ans;
    return 0;
}