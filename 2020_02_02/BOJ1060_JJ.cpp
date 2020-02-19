#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>

using namespace std;

vector<pair<long long int,long long int>> ans; 
vector<long long int> v;

struct d
{
    long long int s,e,left,right;
};
vector<d> range;

long long int l,tmp;
int n;
bool check[101];

void range_solve()
{
    while(range.size()>0)
    {
        long long int minimum=999999999999999999;
        int index=0;
        for(int i=0;i<range.size();i++)
        {
            if(minimum>((range[i].left-range[i].s+1)*(range[i].e-range[i].left+1)))
            {
                index=i;
                minimum=(range[i].left-range[i].s+1)*(range[i].e-range[i].left+1);
            }
        }
        //cout<<"before : "<<range[index].s<<" "<<range[index].left<<" "<<range[index].right<<"\n";
        ans.push_back({minimum,range[index].left});
        if(range[index].left<101) check[range[index].left]=true;
        if(range[index].left<range[index].right) 
        {
            ans.push_back({minimum,range[index].right});
            if(range[index].right<101) check[range[index].right]=true;
            range[index].right--;
        }
        range[index].left++;
        if(ans.size()>=n) break;
        //cout<<"after : "<<range[index].s<<" "<<range[index].left<<" "<<range[index].right<<"\n";
        if(range[index].left>range[index].right) 
        {
            if(index==0&&range.size()==1) 
            {
                range.clear();
                break;
            }
            else range.erase(range.begin()+index);
        }
    }
}

int main()
{
    long long int start=1,end;
    memset(check,false,sizeof(check));
    cin>>l;
    for(int i=0;i<l;i++)
    {
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        ans.push_back({0,v[i]});
        if(v[i]<101) check[v[i]]=true;
    }

    cin>>n;
    for(int i=0;i<v.size();i++)
    {
        end=v[i]-1;
        if(end>start) range.push_back({start,end,start,end});
        else if(start==end)
        {
            ans.push_back({0,start});//구간내의 원소가 1개일때
            if(start<101) check[start]=true;
        }
        start=v[i]+1;
    }
    range_solve();
    sort(ans.begin(),ans.end());
    if(ans.size()<n)
    {
        for(int i=1;i<=100;i++)
        {
            if(check[i]==false) ans.push_back({-1,i});
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i].second<<" ";
    return 0;
}