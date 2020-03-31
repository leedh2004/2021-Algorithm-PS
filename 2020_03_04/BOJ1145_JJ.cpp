#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int arr[5];
int lcm[5][5];
int ans = INT_MAX;

int gcd(int a, int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    for(int i=0;i<5;i++) scanf("%d",&arr[i]);
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            //i와 j로 lcm을 만든다.
            if(lcm[i][j]==0 || lcm[j][i]==0) 
            {
                lcm[i][j]= (arr[i]*arr[j])/gcd(arr[i],arr[j]);
                lcm[j][i]= lcm[i][j];
            }
            for(int k=j+1;k<5;k++)
            {
                ans = min(ans,(lcm[i][j]*arr[k])/gcd(lcm[i][j],arr[k]));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}