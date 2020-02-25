#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map <char,int> m;
string alpabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
pair<long long int,int> ans[26];

int main()
{
    int n;cin>>n;
    for(int i=0;i<26;i++) m.insert({alpabet[i],i});
    for(int i=0;i<26;i++) ans[i].second=i;
    for(int i=0;i<n;i++)
    {
        string tmp; cin>>tmp;
        long long int t=1;
        for(int j=tmp.length()-1;j>=0;j--)
        {
            char now=tmp[j];
            ans[m[now]].first=ans[m[now]].first-t;
            t=t*10;
        }
    }
    sort(ans,ans+26);
    long long int answer=0;
    for(int i=0;i<26;i++)
    {
        if(ans[i].first==0) break;
        answer=answer+(i-9)*ans[i].first;
    }
    cout<<answer;
    return 0;
}