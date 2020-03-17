#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

bool sosu[10000001];
bool check[10000001];

void make_sosu()
{
    sosu[0]= false;
    sosu[1] =false;
    sosu[2]= true;
    for(long long int i=2;i<=10000000;i++)
    {  
        for(long long int j=2; (i*j) <=10000000;j++) sosu[i*j]=false;
    }
    return ;
}

int solv()
{
    vector<char> v;
    vector<int> each[10];
    int ans=0,sz,now_num;
    string now;
    cin>>now;
    sz=now.size();
    memset(check,false,sizeof(check));
    for(int i=0;i<sz;i++) v.push_back(now[i]);
    sort(v.begin(),v.end());
    for(int i=1;i<=sz;i++)
    {
        each[i].resize(sz);
        for(int j=1;j<=i;j++)
        {
            each[i][sz-j]=1;
        }
    }
    for(int i=1;i<=sz;i++)
    {
        do
        {
            vector <char> tmp;
            for(int j=0;j<sz;j++) if(each[i][j]==1) tmp.push_back(v[j]);
            do
            {
                string s;
                for(int k=0;k<tmp.size();k++) s=s+tmp[k];
                now_num=stoi(s);
                //cout<<now_num<<"\n";
                if(sosu[now_num] && !check[now_num])
                {
                    ans++;
                    check[now_num] = true;
                }
            } while (next_permutation(tmp.begin(),tmp.end()));
            tmp.clear();
        } while (next_permutation(each[i].begin(),each[i].end() ) );
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    memset(sosu,true,sizeof(sosu));
    make_sosu();
    while (n--) cout<<solv()<<"\n";
    
    return 0;
}