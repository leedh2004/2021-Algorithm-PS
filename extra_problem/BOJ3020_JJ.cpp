#include <iostream>

using namespace std;

int arr1[500001];
int arr2[500001];
int n,h,tmp;
int m=200001;
int k=1;


void ans()
{
    for(int i=h-1;i>0;i--) arr1[i]=arr1[i]+arr1[i+1];
    for(int i=h-1;i>0;i--) arr2[i]=arr2[i]+arr2[i+1];


    for(int i=1;i<=h;i++)
    {
        if(m>(arr1[i]+arr2[h-i+1]))
        {
            m=arr1[i]+arr2[h-i+1];
            k=1;
        }
        else if(m==(arr1[i]+arr2[h-i+1])) k++;
    }
}

int main()
{
    cin>>n>>h;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        if(i%2==0) arr1[tmp]++;
        else arr2[tmp]++;
    }
    
    ans();
    cout<<m<<" "<<k;
    return 0;
}