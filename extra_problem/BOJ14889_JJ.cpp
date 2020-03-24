#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;


int main()
{
    int n,s[21][21];
    int ans=INT_MAX;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) scanf("%d",&s[i][j]);
    }
    vector <int> before,link,start;
    before.resize(n);
    link.resize(n/2);
    start.resize(n/2);
    for(int i=0;i<(n/2);i++) before[i]=1;
    sort(before.begin(),before.end());
    do
    {
        for(int i=0;i<before.size();i++)
        {
            if(before[i]) link.push_back(i+1);
            else start.push_back(i+1);
        }
        int link_v=0;
        int start_v=0;
        for(int i=1;i<=link.size();i++)
        {
            for(int j=1;j<=link.size();j++) link_v=link_v+s[link[i-1]][link[j-1]];
        }
        for(int i=1;i<=start.size();i++)
        {
            for(int j=1;j<=start.size();j++) start_v=start_v+s[start[i-1]][start[j-1]];
        }
        ans=min(ans,abs(link_v-start_v));
        link.clear();
        start.clear();
    } while (next_permutation( before.begin(),before.end() ) );
    printf("%d",ans);
    return 0;
}