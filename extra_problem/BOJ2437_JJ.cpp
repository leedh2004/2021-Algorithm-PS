#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int total_sum;
int arr[1001];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    total_sum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>total_sum+1) break;
        total_sum=total_sum+arr[i];
    }
    cout<<total_sum+1;
    return 0;
}