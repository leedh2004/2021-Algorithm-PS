#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int,int>> ans;
int t,n,m,tmp,x,y;
int before_lank[501];

bool compare(const pair<int,int>& a,const pair<int,int>& b)
{
    return b.second<a.second;
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans.clear();
        memset(before_lank,0,sizeof(before_lank));
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            ans.push_back({tmp,n-i-1});
            before_lank[tmp]=i+1;
        }
        sort(ans.begin(),ans.end());
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            //x가 등수 더 높을때
            if(before_lank[x]<before_lank[y])
            {
                ans[x-1].second--;
                ans[y-1].second++;
            }
            else
            {
                ans[y-1].second--;
                ans[x-1].second++;
            }
        }
        int cnt=n-1;
        bool flag=true;
        sort(ans.begin(),ans.end(),compare);
        for(int i=0;i<n;i++)
        {
            if(cnt!=ans[i].second) flag= false;
            cnt--;
        }
        if(flag==false) cout<<"IMPOSSIBLE\n";
        else 
        {
            for(int i=0;i<n;i++) cout<<ans[i].first<<" ";
            cout<<"\n";
        }
    }
    return 0;
}