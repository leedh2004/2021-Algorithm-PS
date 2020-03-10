#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int t,now;
char tmp;
string str[3];
int arr[3];
int ans =6;

int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        cin>>str[0]>>str[1]>>tmp>>str[2];
        for(int j=0;j<3;j++)
        {
            string front= str[j].substr(0,3);
            string back = str[j].substr(4,3);
            arr[j]=stoi(front)*1000+stoi(back);
        }

        if(tmp=='A') now=0;
        else now =1;

        //cout<<arr[now]<<arr[!now]<<arr[2];

        if(arr[now]==arr[2]) ans=0;
        else if (arr[!now]==arr[2]) ans=min(ans,1);

        int val=arr[now];
        for(int j=1;j<6;j++)
        {
            val=val+20;
            if(val>146000) val = 144000;
            if(val==arr[2]) ans=min(ans,j);
        }
        val=arr[now];
        for(int j=1;j<=6;j++)
        {
            val=val-20;
            if(val<144000) val = 146000;
            if(val==arr[2]) ans=min(ans,j);
        }
        val=arr[!now];
        for(int j=1;j<6;j++)
        {
            val=val+20;
            if(val>146000) val = 144000;
            if(val==arr[2]) ans=min(ans,j+1);
        }
        val=arr[!now];
        for(int j=1;j<=6;j++)
        {
            val=val-20;
            if(val<144000) val = 146000;
            if(val==arr[2]) ans=min(ans,j+1);
        }
        cout<<ans<<"\n";
        ans=6;
    }
    return 0;
}
