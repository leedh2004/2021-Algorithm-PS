#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

string dp[51];
int n,m,cost[11];

string find_max(string s, int num)
{
    int index=-1;
    string now=to_string(num);
    for(int i=0;i<s.length();i++)
    {
        if(num>(s[i] - 48)) 
        {
            index=i;
            break;
        }
    }
    if(index==-1) s=s+now;
    else s.insert(index,now);
    if (s[0]=='0') return "0";
    else return s;
}

bool string_compare(string a, string b)
{
    if(a.length()!=b.length()) return (a.length()>b.length())?true:false;
    else
    {
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
            {
                return (  (int(a[i])>int(b[i])) ?true:false);
            }
        }
    }
    return true;
}


int main()
{
    /*
    while (1)
    {
        string a;cin>>a;
        int n; cin>>n;
        cout<<find_max(a,n)<<"\n";
    }
    */

    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&cost[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if( i-cost[j]>=0 )
            {
                if(dp[i-cost[j]].length()==0 && dp[i].length()==0) dp[i]=to_string(j);
                else if (dp[i-cost[j]].length()==0 && dp[i].length()!=0) 
                {
                    if(string_compare(to_string(j),dp[i])) dp[i]=to_string(j);
                }
                else if (dp[i-cost[j]].length()!=0 && dp[i].length()==0) 
                {
                    dp[i]=find_max(dp[i-cost[j]],j);
                }
                else {
                    string tmp = find_max(dp[i-cost[j]],j);
                    if(string_compare(tmp,dp[i])) dp[i]=tmp;
                }
                
            }
        }
    }
    cout<<dp[m];
    return 0;
}
