#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int degree[10001];
int cost[10001];
bool visited[10001];
int dp[10001][2];
vector<int> adj[10001];
vector<int> one_way[10001];
vector<int> sett;
int n;


int recursive(int node_index , bool is_in_set)
{
    if(dp[node_index][is_in_set]!=0) return dp[node_index][is_in_set];
    int now =0;
    for(int i=0;i<one_way[node_index].size();i++)
    {
        if(is_in_set) now = now + recursive(one_way[node_index][i],0);
        else
        {
            now = now + max(recursive(one_way[node_index][i],1),recursive(one_way[node_index][i],0));
        }
    }
    if(is_in_set) now = now + cost[node_index];
    return dp[node_index][is_in_set] = now;
}

int find_leaf_node()
{
    for(int i=1;i<=n;i++)
    {
        if(degree[i]==1) return i;
    }
    return 0;
}

void make_one_way_tree(int node)
{
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
        {
            one_way[node].push_back(adj[node][i]);
            make_one_way_tree(adj[node][i]);
        }
    }
    return ;
}

void back_tracking(int node,bool is_in_set)
{
    if(is_in_set) sett.push_back(node);
    for(int i=0;i<one_way[node].size();i++)
    {
        if(is_in_set) back_tracking(one_way[node][i],0);
        else
        {
            if(dp[one_way[node][i]][0] <dp[one_way[node][i]][1]) back_tracking(one_way[node][i],1);
            else back_tracking(one_way[node][i],0);
        }
    }
}

int main()
{
    int tmp,st,ed;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&cost[i]);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&st,&ed);
        adj[st].push_back(ed);
        adj[ed].push_back(st);
        degree[st]++;
        degree[ed]++;
    }
    int root = find_leaf_node();
    make_one_way_tree(root);
    printf("%d\n",max(recursive(root , false) , recursive(root, true)));
    if(dp[root][0]<dp[root][1]) back_tracking(root,1);
    else back_tracking(root,0);
    sort(sett.begin(),sett.end());
    for(int i=0;i<sett.size();i++) printf("%d ",sett[i]);
    return 0;
}