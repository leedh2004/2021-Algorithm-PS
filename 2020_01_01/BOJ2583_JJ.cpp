#include <iostream>
#include <queue>

using namespace std;

int n,m,num_of_square;
int x[4]={-1,0,1,0};
int y[4]={0,1,0,-1};
int visit[101][101];
bool table[101][101];
int first_x,second_x;
int first_y,second_y;
priority_queue<int,vector<int>,greater<int> > PQueue;

bool isinthetable(int N,int M, int x, int y)
{
	return (x>=0&&x<N)&&(y>=0&&y<M);	
}

void bfs(int start_n, int start_m)	
{
	if(table[start_n][start_m]==true||visit[start_n][start_m]!=0) 
	{
		//printf("don't check %d,%d\n",start_n,start_m);
		return ;
	}
	queue<pair<int,int> > q;
	q.push(pair<int,int>(start_n,start_m));
	visit[start_n][start_m]=1;
	int N,M;
	int next_N,next_M;
	int last_size=1;
	while(!q.empty())
	{
		N=q.front().first;
		M=q.front().second;
		//printf("now_N: %d now_M: %d\n",N,M);
		q.pop();
		//if((N==n-1)&&(M==n-1)) break;

		for(int i=0;i<4;i++)
		{
			next_N=N+x[i];
			next_M=M+y[i];
			if(isinthetable(n,m,next_N,next_M) && (visit[next_N][next_M]==0) && table[next_N][next_M]==false)
			{

				//printf("near search - now_N: %d now_M: %d\n",next_N,next_M);
				visit[next_N][next_M]=last_size+1;
				//printf("now size is %d\n", visit[next_N][next_M]);
				q.push(pair<int,int>(next_N,next_M));
				last_size = visit[next_N][next_M];
			}
		}
		if(q.empty()) PQueue.push(visit[N][M]);
	}
}

int main()
{
	cin>>m>>n>>num_of_square;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			visit[n][m]=0;
			table[n][m]=false;
		}
	}
	for(int k=0;k<num_of_square;k++)
	{
		cin>>first_x>>first_y;
		cin>>second_x>>second_y;
		for(int i=first_x;i<second_x;i++)
		{
			for(int j=first_y;j<second_y;j++) table[i][j]=true;
		}
		
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) bfs(i,j);
	}
	cout<<PQueue.size()<<'\n';
	while(!PQueue.empty())
	{
		if(PQueue.size()==1) cout<< PQueue.top();
		else
		{
			cout<< PQueue.top()<<" ";
		}
		PQueue.pop();
	}
	return 0;
}