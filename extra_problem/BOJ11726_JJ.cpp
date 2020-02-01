#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
//int max_bar;
long long int ans=0;
int dp[1001];
//vector <int> v;

/*
void cal_number_of_way(int i)
{
    int n_tmp=n;
    for(int k=0;k<i;k++) 
    {
        v.push_back(2);
        n_tmp=n_tmp-2;
    }
    for(int k=0;k<n_tmp;k++) v.push_back(1);
    sort(v.begin(),v.end());
    do
    {
        ans++;
    }while(next_permutation(v.begin(),v.end()));
    v.clear();
}
*/
int main()
{
    cin>>n;
    //max_bar=n/2;
    //for(int i=0;i<=max_bar;i++) cal_number_of_way(i);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]=dp[i]%10007;
    }
    cout<<dp[n];
    return 0;
}