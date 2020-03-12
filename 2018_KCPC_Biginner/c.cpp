#include <iostream>
#include <cstdio>

using namespace std;

char ms[2];
char tk[2];

int main()
{
    cin>>ms[0]>>ms[1]>>tk[0]>>tk[1];
    if(ms[0]==ms[1])
    {
        if(ms[0]=='R' && (tk[0]=='P'|| tk[1]=='P'))
        {
            cout<<"TK";
            return 0;
        }
        else if(ms[0]=='S' && (tk[0]=='R'|| tk[1]=='R'))
        {
            cout<<"TK";
            return 0;
        }
        else if(ms[0]=='P' && (tk[0]=='S'|| tk[1]=='S'))
        {
            cout<<"TK";
            return 0;
        }
    }
    if(tk[0]==tk[1])
    {
        if(tk[0]=='R' && (ms[0]=='P'|| ms[1]=='P'))
        {
            cout<<"MS";
            return 0;
        }
        else if(tk[0]=='S' && (ms[0]=='R'|| ms[1]=='R'))
        {
            cout<<"MS";
            return 0;
        }
        else if(tk[0]=='P' && (ms[0]=='S'|| ms[1]=='S'))
        {
            cout<<"MS";
            return 0;
        }
    }
    cout<<"?";
    return 0;

}