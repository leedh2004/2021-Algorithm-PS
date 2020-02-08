#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
int box_left;
int ans=1;
int arr[100001];

int main()
{
    scanf("%d %d",&n,&m);
    box_left=m;
    if(n==0)
    {
        printf("0");
        return 0;
    }
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&arr[i]);
        if(box_left-arr[i]<0)
        {
            box_left=m;
            ans++;
        }
        box_left=box_left-arr[i];
    }
    printf("%d",ans);
    return 0;
}