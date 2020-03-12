#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<string> no_jam;

struct retun
{
    bool pos;
    int count;
};


int score[100];
int num;
int count;
int max_index=-1;
float max_val=-1;

retun is_possible(int x)
{
    int x_index=0;
    int y_index=0;
    count=0;
    while(no_jam[x].size()>=x_index)
    {
        if(no_jam[x][x_index]==str[y_index])
        {
            x_index++;
            y_index++;
        }
        else
        {
            count++;
            x_index++;
        }
    }
    y_index--;
    return {(y_index==str.size()),count};
}

int main()
{  
    cin>>str>>num;
    no_jam.resize(num);
    for(int i=0;i<num;i++) cin>>no_jam[i]>>score[i];
    for(int i=0;i<num;i++)
    {
        retun now = is_possible(i);
        float now_val = (float)score[i]/now.count;
        if(now.pos==true && now_val>max_val)
        {
            max_index=i;
            max_val=now_val;
        }
    }
    if(max_index==-1) cout<<"No Jam";
    else cout<<no_jam[max_index];
    return 0;
    
}