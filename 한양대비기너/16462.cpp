#include <iostream>
#include <string>

using namespace std;

int n;
int score=0;
float sc;

int ban(float sc)
{
    int tmp = (int)sc;
    if(sc-(float)tmp<0.5) return tmp;
    else return tmp+1;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string tmp;
        cin>>tmp;
        for(int j=0;j<tmp.size();j++)
        {
            if(tmp[j]=='0'||tmp[j]=='6') tmp[j]='9';
        }
        if(stoi(tmp)>100) score=score+100;
        else score=score+stoi(tmp);
        //cout<<"total : "<<score<<"\n";
    }
    sc= ((float)score)/((float)n);
    //cout<<sc;
    cout<<ban(sc);
    return 0;
}