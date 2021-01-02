#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long int ll;
int n,m;
int cost[1002][1002];
ll dp_int[1002][1002];
ll dp_float[1002][1002][2];
ll ans = 0;
ll ans2 = 0;

ll dfs_dp_float_up(int x,int y);
ll dfs_dp_float_down(int x,int y);


bool is_in(int x,int y){
    return 0<=x && x<= n+1 && 0<=y;
}

ll dfs_dp_int (int x, int y){
    //나가는경우
    if(!is_in(x,y)) return 0;

    //dp
    if(dp_int[x][y]!=-1) return dp_int[x][y];

    //상하
    ll tmp = max(dfs_dp_int(x-1,y-1),dfs_dp_int(x+1,y-1));

    //dp값 저장 및 return
    return  dp_int[x][y] = max(tmp,dfs_dp_int(x,y-2)+cost[x][y-1])+cost[x][y];
}


ll dfs_dp_float_up(int x,int y){
    if(!is_in(x,y)) return 0;
    if(dp_float[x][y][0]!=-1) return dp_float[x][y][0];
    return dp_float[x][y][0] = max(dfs_dp_float_up(x+1,y-1),dfs_dp_float_down(x,y-1))+cost[x][y];
}


ll dfs_dp_float_down(int x,int y){
    if(!is_in(x,y)) return 0;
    if(dp_float[x][y][1]!=-1) return dp_float[x][y][1];
    return dp_float[x][y][1] =  max(dfs_dp_float_down(x-1,y-1),dfs_dp_float_up(x,y-1))+cost[x][y];
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            scanf("%d",&cost[i][j]);
        }
    }
    memset(dp_int,-1,sizeof(dp_int));
    memset(dp_float,-1,sizeof(dp_float));
    
    for(int i=1;i<=n;i++) ans = max(ans,dfs_dp_int(i,m+1));
    

    for(int i=1;i<=n;i++){
        ans2 = max(ans2,dfs_dp_float_up(i,m+1));
        ans2 = max(ans2,dfs_dp_float_down(i,m+1));
    }

    printf("%lld\n",max(ans,ans2));
    return 0;
}