#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


int table[21][21],n,num;
vector<pair<int,int>> cutcut;
int ans=0;

int how_many(int x1,int y1, int x2, int y2, int val)
{
    int total=0;
    for(int i=x1;i<=x2;i++)
    {
        for(int j=y1;j<=y2;j++)
        {
            if(table[i][j]==val) total++;
        }
    }
    return total;
}

bool poss_cut(int x1,int y1, int x2, int y2,int c_x, int c_y, bool dir)
{
    bool flag=true;
    //가로로 자를때
    if(dir)
    {
        for(int j=y1;j<=y2;j++){
            if(j!=c_y && table[c_x][j]!=0) flag=false;
        }
    }
    //세로로 자를때
    else
    {
        for(int i=x1;i<=x2;i++){
            if(i!=c_x && table[i][c_y]!=0) flag=false;
        }
    }
    return flag;
}

void pp(int x1,int y1, int x2, int y2,int c_x, int c_y)
{
    for(int i=x1;i<=x2;i++)
    {
        for(int j=y1;j<=y2;j++)
        {
            if(i==c_x && j == c_y) printf("* ");
            else printf("%d ",table[i][j]);
        }
        printf("\n");
    }
}

int cut(int x1,int y1, int x2, int y2, bool dir)
{   
    int now =0;
    int num_c = how_many(x1,y1,x2,y2,1);
    int num_j = how_many(x1,y1,x2,y2,2);
    if(num_c==0 && num_j==1) return 1;
    else if (num_j==0 || (num_j==1 && num_c>=1) || (num_j>=2&&num_c==0)) return 0;
    for(int i=0;i<num;i++)
    {   
        if(!(x1<=cutcut[i].first && cutcut[i].first<=x2 && y1<=cutcut[i].second && cutcut[i].second<=y2)) continue;
        if(!poss_cut(x1,y1,x2,y2,cutcut[i].first,cutcut[i].second,dir)) continue;
        int x1_x2,x2_x2,y1_y2,y2_y2;
        if(dir)
        {
            x1_x2=cutcut[i].first-1;
            y1_y2=y2;
            x2_x2=cutcut[i].first+1;
            y2_y2=y1;
        }
        else
        {
            x1_x2=x2;
            y1_y2=cutcut[i].second-1;
            x2_x2=x1;
            y2_y2=cutcut[i].second+1;
        } 
        now = now + cut(x1,y1,x1_x2,y1_y2,!dir)*cut(x2_x2,y2_y2,x2,y2,!dir);
    }
    return now;
} 


int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) 
        {
            scanf("%d",&table[i][j]);
            if(table[i][j]==1) 
            {
                cutcut.push_back({i,j});
                num++;
            }
        }
    }
    ans=cut(1,1,n,n,true)+cut(1,1,n,n,false);
    printf("%d",ans?:-1,ans);
    return 0;
}