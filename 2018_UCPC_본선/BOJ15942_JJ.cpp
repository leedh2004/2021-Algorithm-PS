#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

int n,k,p;
int order[200000];
bool check[200001];

int now_above = 1;
int now_below;

int get_depth(int index){
    if(index==0) return 1;
    return get_depth(index-1) +1;
}

void above(int position){
    if(position!=0)above((position-1)/2);
    order[position] = now_above;
    check[now_above] = true;
    now_above++;
}

void below(int position){
    //범위넘어가는 경우
    if(position>=n) return ;
    below(position*2+2);
    below(position*2+1);
    order[position] = now_below;
    check[now_below] = true;
    now_below--;
}


int main(){
    //입력
    scanf("%d%d%d",&n,&k,&p);
    p--;
    now_below = n;

    bool flag_up = true;
    bool flag_down = true;

    //해당 포지션 기준 위쪽 값 대입
    above(p);
    if (order[p]>k) flag_up = false;
    
    // printf("-----\n");
    // for(int i=0;i<n;i++)printf("%d\n",order[i]);

    check[order[p]] = false;
    order[p] = k;
    check[k] = true;


    below(p);
    if (order[p]<k) flag_down = false;

    // printf("-----\n");
    // for(int i=0;i<n;i++)printf("%d\n",order[i]);

    check[order[p]] = false;
    order[p] = k;
    check[k] = true;

;

    if(!(flag_up &&flag_down)) {
        printf("-1\n");
        return 0;
    }

    // printf("-----\n");
    
    //사용안한 숫자 체크
    priority_queue<int> pq;
    for(int i=1;i<=n;i++){
        if(check[i]==false) pq.push(-i);
    }

    for(int i=0;i<n;i++){
        if(order[i]==0){
            printf("%d\n",-pq.top());    
            pq.pop();
        }
        else{
            printf("%d\n",order[i]);
        }
    }
    return 0;
}
