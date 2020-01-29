#include <iostream>
#include <cstdio>
#include <string>

//ios::sync_with_stdio(false);

using namespace std;

int dp[31][31]={0};
string s;
int anw=0;

void palindrome_dp()
{
    for(int i=3;i<=s.length();i++) //i가 사이즈가 된다
    {   
        for(int j=1;j<=s.length()-i+1;j++) //몇개의 집합이 있는가?
        {
            tmp =j+i-1;
            if(dp[j-1][tmp-1]==1 && s[j]==s[tmp]) dp[j][tmp]=1;
        }
    }
}



int main()
{
    cin>>s;
    for(int i=0;i<s.length();i++) 
    {
        dp[i+1][i+1]=1;
        anw++;
    }
    for(int i=0;i<s.length()-1;i++) 
    {
        if(s[i]==s[i+1]) {
            dp[i+1][i+2] = 1;
            anw++;
        }
    }
    palindrome_dp();
    cout<<anw;
    return 0;
}