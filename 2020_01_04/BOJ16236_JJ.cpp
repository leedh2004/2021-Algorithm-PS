#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;


int n,tmp;
int table[21][21];
int check[21][21];
int d[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int t=-1;
int total=0;
int c=0;
int tmpx,tmpy;

struct fish{
    int x;
    int y;
    int s;
    bool live;
};

vector<fish> v;
fish shark;
queue<pair<int,int> > q;

int is_in(int x ,int y)
{
    if ((0<x&&x<=n)&&(0<y&&y<=n)) return 1;
    else return 0;
}

int bfs()
{
    while(!q.empty())
    {
        int q_s=q.size();
        t++;
        for(int i=0;i<q_s;i++)
        {
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            if( (table[x][y]>0) && (v[table[x][y]-1].live==true) && (shark.s>v[table[x][y]-1].s) )
            {
                for(int j=i+1;j<q_s;j++)
                {
                    tmpx=q.front().first;
                    tmpy=q.front().second;
                    q.pop();
                    if((table[tmpx][tmpy]>0) && (v[table[tmpx][tmpy]-1].live==true) && (shark.s>v[table[tmpx][tmpy]-1].s))
                    {
                        if(tmpx<x)
                        {
                            x=tmpx;
                            y=tmpy;
                        }
                        else if((tmpx==x)&&(tmpy<y))
                        {
                            x=tmpx;
                            y=tmpy;
                        }
                    }
                } 
                while(!q.empty()) q.pop();
                memset(check,0,sizeof(check));
                q.push({x,y});
                check[x][y]=1;
                c++;
                if(c%shark.s==0)
                {
                    c=0;
                    shark={x,y,shark.s+1,true};
                }
                else shark={x,y,shark.s,true};
                v[table[x][y]-1].live=false;
                table[x][y]=0;
                total=total+t;
                t=-1;
                break;
            }

            for(int j=0;j<4;j++)
            {
                int n_x=x+d[j][0];
                int n_y=y+d[j][1];
                if( is_in(n_x,n_y) && (check[n_x][n_y]==0) )
                {
                    if(table[n_x][n_y]>0 && v[table[n_x][n_y]-1].s>shark.s) continue;
                    q.push({n_x,n_y});
                    check[n_x][n_y]=1;
                }
            }
        }
    }
    return total;
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>tmp;
            if(0<tmp&&tmp<9){
                v.push_back({i,j,tmp,true});
                table[i][j]=v.size();
            }
            else if(tmp==9) {
                shark={i,j,2,true};
                table[i][j]=0;
            }
            else table[i][j]=0;
        }
    }

    memset(check,0,sizeof(check));
    q.push({shark.x,shark.y});
    check[shark.x][shark.y]=1;

    cout<<bfs();
    return 0; 
}