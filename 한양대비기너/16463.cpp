#include <iostream>

using namespace std;

int now_year=2019;
int goal_year;

//1-월  5- 금 6-토 7-일

int fri;
int ans=0;
int days[12]={31,31,28,31,30,31,30,31,31,30,31,30};


int main()
{
    cin >>goal_year;
    fri= 2+(13-1)%7;
    bool flag=true;
    while (now_year<=goal_year)
    {
        for(int i=0;i<12;i++)
        {
            if(flag)
            {
                flag=false;
                continue;
            }
            if(i==2 && ( (now_year%4==0&&now_year%100!=0)||(now_year%400==0)))
            {
                fri=(fri+days[i]+1)%7;
            }
            fri=(fri+days[i])%7;
            if(fri==5) ans++;
        }
        now_year++;
    }
    cout<<ans;
}