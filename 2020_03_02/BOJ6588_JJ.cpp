#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool sosu[1000001];
int a,b;

void make_sosu()
{
    sosu[0]= false;
    sosu[1] =false;
    sosu[2]= false;
    for(long long int i=2;i<=1000000;i++)
    {  
        for(long long int j=i; (i*j) <=1000000;j++) sosu[i*j]=false;
    }
    return ;
}


void check_is_pos(int x)
{
    a=0;
    b=0;
    for(int i=0;i<=x;i++)
    {
        if(sosu[i]&&sosu[x-i])
        {
            a=i;
            b=x-i;
            break;
        }
    }
    return ;
}

int main()
{
    int val;
    memset(sosu,true,sizeof(sosu));
    make_sosu();
    while (1)
    {
        scanf("%d",&val);
        if(val==0) break;
        check_is_pos(val);
        if(a==0 && b==0) printf("Goldbach's conjecture is wrong.\n");
        else printf("%d = %d + %d\n",val,a,b);
    }
    return 0;
}