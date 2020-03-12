#include <iostream>
#include <string>

using namespace std;

string num;

char arr[4]={'2','0','8','1'};
int count[4];
bool flag[4];
bool tmp_flag=false;

int main()
{
    cin>>num;
    for(int i=0;i<num.size();i++)
    {
        bool tmp=false;
        for(int j=0;j<4;j++)
        {
            if(num[i]==arr[j])
            {
                count[j]++;
                flag[j]=true;
                tmp=true;
            }
        }
        if(tmp==false) tmp_flag=true;
    }

    bool tmp2_flag=false;
    for(int i=0;i<4;i++)
    {
        if(flag[i]==false) tmp2_flag=true;
    }
    bool tmp3_flag=false;
    for(int i=1;i<4;i++)
    {
        if(count[i]!=count[0]) tmp3_flag=true;
    }


    if(tmp_flag) cout<<"0";
    else if (tmp2_flag) cout<<"1";
    else if(tmp3_flag) cout<<"2";
    else cout <<"8";
    return 0;
}