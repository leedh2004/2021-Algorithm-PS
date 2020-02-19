#include <iostream>
#include <string>
#include <cmath>

using namespace std;


struct s
{
    int T,A,G,C;
};

s score[1000];
int n,m;
int hd=0;

string decide_string()
{
    char ans[51];
    for(int i=0;i<m;i++)
    {
        int max_num=max(max(score[i].T,score[i].A),max(score[i].C,score[i].G));
        if(max_num==score[i].T) ans[i]='T';
        if(max_num==score[i].G) ans[i]='G';
        if(max_num==score[i].C) ans[i]='C';
        if(max_num==score[i].A) ans[i]='A';
    }
    ans[m]='\0';
    return ans;
}

void cal_hd(int i,string str)
{
    if('T'!=str[i]) hd=hd+score[i].T;
    if('A'!=str[i]) hd=hd+score[i].A;
    if('C'!=str[i]) hd=hd+score[i].C;
    if('G'!=str[i]) hd=hd+score[i].G;
}

void score_up(int j,char tmp)
{
    if(tmp=='T') score[j].T++;
    else if(tmp=='A') score[j].A++;
    else if(tmp=='C') score[j].C++;
    else score[j].G++;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        for(int j=0;j<m;j++) score_up(j,str[j]);
    }
    string str = decide_string();
    cout<<str<<'\n';
    for(int i=0;i<m;i++) cal_hd(i,str);
    cout<<hd;
    return 0;
}