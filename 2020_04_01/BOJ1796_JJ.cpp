#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int idx[27][2];
int ans=987654321;
string str;


void recur(int alpha, int now_cursor, int total)
{
    if(alpha > 'z') 
    {
        ans=min(ans,total);
        return ;
    }
    
    //1개일때
    if(idx[alpha-'a'+1][0]==idx[alpha-'a'+1][1])recur(alpha+1,idx[alpha-'a'+1][0],  total +abs(now_cursor - idx[alpha-'a'+1][0]));

    //2개이상일때
    else if(idx[alpha-'a'+1][1]!=0)
    {
        recur(alpha+1,idx[alpha-'a'+1][0], total+abs(now_cursor - idx[alpha-'a'+1][1])+ abs(idx[alpha-'a'+1][0] - idx[alpha-'a'+1][1]) );
        recur(alpha+1,idx[alpha-'a'+1][1], total+abs(now_cursor - idx[alpha-'a'+1][0])+ abs(idx[alpha-'a'+1][0] - idx[alpha-'a'+1][1]) );
    }
    else recur(alpha+1,now_cursor,total);
    return ;
}

int main()
{
    cin>>str;
    str= " "+str;

    for(int i='a';i<='z';i++) idx[i-'a'+1][0]=1001;
    //각각의 최소 최대 인덱스 저장
    for(int i='a';i<='z';i++)
    {
        for(int j=1;j<str.length();j++)
        {
            if(i==str[j])
            {
                idx[i-'a'+1][0] = min(idx[i-'a'+1][0],j);
                idx[i-'a'+1][1] = max(idx[i-'a'+1][1],j);
            }
        }
    }
    recur('a',1,0);
    printf("%d\n",ans+int(str.length())-1);
}