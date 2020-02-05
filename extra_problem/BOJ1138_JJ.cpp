#include <iostream>

using namespace std;

int n;
int arr[11];
int ans[11];


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        int tmp=1;
        for(int j=1;j<=n;j++)
        {
            if(ans[j]>0) 
            {
                tmp++;
            }
            else
            {
                if(arr[i]==0) 
                {
                    ans[tmp]=i;
                    break;
                }
                else
                {
                    arr[i]--;
                    tmp++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}