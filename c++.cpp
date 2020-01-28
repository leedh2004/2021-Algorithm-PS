//////////////////////////////////////////////////////////////////////////
//알고리즘
/* 유클리드 호제법 
--최대공약수--
1. 임의의 2 자연수 a,b일때 큰값이 a라면 a%b=n
2. n이 0일때 b가 최대공약수이다
3. n이 0이 아니라면 a=b , b=n으로 다시 구한다
--최소공배수--
1. lcm(a,b)=a*b/gcd(a,b)
*/

int gcd(int a, int b)
{
    int c;
	while(b)
	{
		c = a % b;
		a = b;
		b = c;
	}
    return a;
}

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

//다이스트라
#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;
 
int main()
{
    int V,E;
    scanf("%d %d", &V ,&E); //노드의 갯수와 엣지의 갯수를 입력받습니다. 
    int start;
    scanf("%d",&start);        //시작점을 입력받습니다. 
    vector<pair<int,int> > arr[V+1];
    
    for(int i=0;i<E;i++){
        int from,to,val;
        scanf("%d %d %d", &from , &to,&val); //그래프 상의 엣지들에 대한 정보를 입력받습니다. 
        arr[from].push_back({to,val});
    }
    int dist[V+1];    //최단거리를 갱신해주는 배열입니다. 
    fill(dist,dist+V+1,INF);    //먼저 무한대로 전부 초기화를 시켜둡니다. 
    priority_queue<pair<int,int> > qu;     
    
    qu.push({0,start});    //우선순위 큐에 시작점을 넣어줍니다. 
    dist[start]=0;    //시작점의 최단거리를 갱신합니다. 
    
    while(!qu.empty()){
        int cost=-qu.top().first;    // cost는 다음 방문할 점의 dist값을 뜻합니다. 
        int here=qu.top().second;     // here을 방문할 점의 번호를 뜻합니다 
        
        qu.pop();
            
        for(int i=0; i<arr[here].size(); i++){
            int next=arr[here][i].first;
            int nextcost=arr[here][i].second;
            
            if(dist[next] > dist[here] + nextcost){    
                //현재 next에 저장된 dist의값보다 현재의 점을 거쳐서 갈 경우가 
                // 거리가 더짧으면 갱신해 주고 큐에 넣습니다. 
                dist[next]=dist[here]+nextcost;
                qu.push({-dist[next],next});
            }
        }
        
    }
    for(int i=1;i<=V;i++){
        printf("%d\n", dist[i]);
    }
}

//////////////////////////////////////////////////////////////////////////
//유용한 라이브러리
#include<algorithm>
sort(v.begin(),v.end());			//정렬

do {								//순열
		for (int i = 0; i < 6; i++) {
			if (vt[i] == 1)
				cout << arr[i] << " ";
		}
		cout << endl;
}while (next_permutation(vt.begin(), vt.end()));
//조합을 쓰고 싶다면 같은 사이즈의 벡터만들고 뽑을 갯수만큼 1넣고 돌려주면 됨


#include<string.h>
memset(start,value,size);
fill_n(start,size,value);


#include<vector>
vector<int> v;
vector<int> v(5);       //원소 5개
vector<int> v(5,2);     //2로 초기화된 원소 5개
vector<int> v2(v1);     //v1을 복사
vector<int>::iterator i=v.begin();  //이터레이터 선언
*iter // 해당값 

v.assign(5,2);          //2의값으로 5개원소 할당
v.begin();              //첫번째 원소 참조
v.end();                //마지막 원소 참조
v.front();              //첫번째 원소 참조
v.back();               //마지막 원소 참조
v.size();               //원소의 갯수
v.capacity();           //할당된 공간의 크기
v.insert(2,3,4);        //2번째 위치에 3개 4를 삽입(뒤에 원소들은 밀림)
v.empty();              //비어있다면 true없다면 false

pair<int, int> pl;
int tmp = pl.first;
int tmp = pl.second;

#include<queue>
queue<int> q;
q.push(element);
q.pop();
q.front();
q.back();
q.empty();
q.size();

//우선순위가 높은 애들부터 나온다, heap으로 구성되어있음
priority_queue<int> pq;

#include<stack>
s.push();
s.pop();
s.top();
s.empty();
s.size();

#include<set>
//균형 이진트리로 구성
//중복되지않고, insert로 넣어주면 자동정렬됨
set<int> s;
s.begin();
s.end();
s.insert(10);
s.find(10);             //존재한다면 해당 인덱스 반복자 반환 없으면 s.end()반복자 반환
s.count(10);            //원소의 갯수를 파악(0혹은 1)
s.empty();
s.size();
s.upper_bound(k);       //원소 k가 끝나는 구간의 반복자
s.lower_bound(k);       //원소 k가 시작하는 구간의 반복자
s.equal_range(k);       //원소 k가 시작하고 끝나는 구간의 반복자 pair객체 반환
//////////////////////////////////////////////////////////////////////////
//c언어기본

//1. 조건연산자
//조건?TRUE:FALSE;
int data = num1>num2?num1:num2;
//참일때 num1 거짓일때 num2
//////////////////////////////////////////////////////////////////////////