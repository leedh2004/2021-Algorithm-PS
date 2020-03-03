#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int n,p;
vector<pair<int,pair<int,int> > > edge;
string tmp;


int main()
{
    int now=0;int ans=0;int total=0;int val;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) 
        {
            cin>>val;
            if(i==j) continue;
            edge.push_back( {val,{i,j}} );
        }
    }

    //cost가 낮은 순으로 정렬
    sort(edge.begin(),edge.end());

    //현재 발전소들의 상태 입력 받음
    string tmp;cin>>tmp;tmp=" "+tmp;
    for(int i=1;i<=n;i++) 
    {
        if(tmp[i]=='Y') 
        {
            now=now+1;
            total++;
        }
        now=now<<1;
    }
    now=now>>1;
    //printf("%d\n",now);
    cin>>p;

    //이미 충족된경우
    if(total>=p)
    {
        printf("0");
        return 0;
    }
 
    //남은 발전소 횟수만큼 돈다
    for(int i=total;i<=p;i++)
    {
        //모든 간선들에 대하여 확인
        for(int j=0;j<edge.size();j++)
        {
            int bit_mask1 = ~(1<<(n-edge[j].second.first));
            int bit_mask2 = 1<< (n-edge[j].second.second);

            //현재 꺼져있는 발전소에서 시작하는 edge
            if( (now|bit_mask1)==now) continue;

            //현재 켜져있는 발전소로 도착하는 edge
            if( (now&bit_mask2)==bit_mask2) continue;

            now=now|(1<<(n-edge[j].second.second));
            ans=ans+edge[j].first;
            total++;
            break;
        }
    }
    printf("%d",(total==p)?ans:-1);
    return 0;
}