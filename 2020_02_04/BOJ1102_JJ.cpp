#include <iostream>
#include <queue>
#include <string>
#include <climits>

using namespace std;

priority_queue<pair<int,int>> pq;
int n,p;
int cost[17][17];
int dist[17];
int ans=0;
int now=0;

int solve()
{
    if(now==p) return 0;
    while(!pq.empty()||now<p)
    {
        int n_c=-pq.top().first;
        int n_i=pq.top().second;
        pq.pop();
        if(dist[n_i]<n_c) continue;
        for(int i=1;i<=n;i++)
        {
            int next=i;
            int nextdist = n_c+cost[n_i][i];
            if(dist[next]>nextdist)
            {
                now++;
                ans=ans+nextdist;
                //cout<<ans<<"\n";
                dist[next]=nextdist;
                pq.push({-nextdist,next});
            }
        }
    }
    if(now==p)return ans;
    else return -1;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>cost[i][j];
    }
    string tmp;cin>>tmp;tmp=" "+tmp;
    fill(dist,dist+17,INT_MAX);
    for(int i=1;i<=n;i++) 
    {
        if(tmp[i]=='Y')
        {
            now++;
            dist[i]=0;
            pq.push({0,i});
        }
    }
    cin>>p;
    cout<<solve();
    return 0;
}