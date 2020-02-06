#include <iostream>
#include <queue>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct meet{
    long long int w,c;
};

meet arr[100001];
long long int n,m;
long long int ans=0;
long long int mini= 2147483647;
long long int totalmeet=0;
int flag=0;

bool compare(const meet &a, const meet &b)
{
    if(a.c<b.c) return true;
    else if(a.c==b.c && a.w>b.w) return true;
    else return false;
}


int main()
{
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld %lld",&arr[i].w,&arr[i].c);
    sort(&arr[1],&arr[n+1],compare);
    arr[0].c=-1;
    for(int i=1;i<=n;i++)
    {
        totalmeet=totalmeet+arr[i].w;
        if(arr[i].c==arr[i-1].c)  ans=ans+arr[i].c;
        else ans=arr[i].c;
        if(m<=totalmeet) 
        {
            mini=min(mini,ans);
            flag=1;
        }
    }
    printf("%d",flag?mini:-1);
    return 0;
}




/*
long long int n,m;
long long int ans=0;
long long int sum=0;
long long int w,c;
long long int tmpw,tmpc;
long long int max_cost=0;

struct meet
{
    long long int w,c;
};

meet tmpmeet;

//cost 낮은순으로, cost가 같다면 weight가 높은 순으로
struct compare
{
    bool operator()(meet &f,meet &c)
    {
        if(f.c<c.c) return false;
        if(f.c==c.c&&f.w>c.w) return false;
        return true;
    }
};

priority_queue<meet,vector<meet>,compare> pq;

long long int solve()
{   
    //최대 코스트 초기화
    max_cost=-1;
    tmpc=2147483647;
    while(!pq.empty())
    {
        tmpmeet=pq.top();
        pq.pop();
        //cout<<tmpmeet.c<<" "<<tmpmeet.w<<"\n";
        if(max_cost<tmpmeet.c)
        {
            sum=sum+tmpmeet.w;
            ans=tmpmeet.c;
            max_cost=tmpmeet.c;
            if(sum>m)  return min(ans,tmpc); //tmpc(같은 cost로 이루어진 total cost)와 ans(수가 증가하여 커진 코스트)중에 작은거 리턴
        }
        else
        {
            ans=ans+tmpmeet.c;
            sum=sum+tmpmeet.w;
            if(sum>m) //수가 커지지않았지만 목표치의 고기량을 달성한경우
            {
                tmpc=ans; //토탈 cost
                while( pq.top().c == tmpmeet.c) pq.pop(); //같은 cost를 다 빼준다
                if(pq.size()==0) return ans; //다 빼줬는데 사이즈가 0이면 cost를 리턴해준다
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&w,&c);
        pq.push({w,c});
    }
    printf("%lld",solve());
    return 0;
}
*/