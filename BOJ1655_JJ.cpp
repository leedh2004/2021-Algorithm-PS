#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;


int n,tmp;
priority_queue<int> smaller; //Max heap;
priority_queue<int,vector<int>,greater<int> > bigger; //Min heap;


int main()
{ 
    scanf("%d",&n);
    scanf("%d",&tmp);
    smaller.push(tmp);
    printf("%d\n",smaller.top());
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&tmp);
        if(tmp>smaller.top()) bigger.push(tmp);
        else smaller.push(tmp);
        if(smaller.size()<bigger.size())
        {
            smaller.push(bigger.top());
            bigger.pop();
        }
        else if(smaller.size()>bigger.size()+1)
        {
            bigger.push(smaller.top());
            smaller.pop();
        }
        printf("%d\n",smaller.top());
    }
    return 0;
}

