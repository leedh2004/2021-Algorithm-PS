#include <iostream>

using namespace std;

long long int arr[100001];
int n;
long long int sum=0;

int main()
{
    cin>>n;
    arr[0]=1;
    arr[1]=3;
    for(int i=2;i<=n;i++) arr[i]=(arr[i-1]*2+arr[i-2])%9901;
    cout<<arr[n];
    return 0;
}