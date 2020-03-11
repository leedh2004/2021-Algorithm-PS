#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
// 모든 path를 다 검색하고, 최장거리를 구한다.

vector<pair<int, int>> v[10001];
vector<pair<int, int>> g[10001]; // 거꾸로 저장.
int indegree[10001];
int d[10001]; // 거리를 담음
int t[10001];
int visited[10001];

int start, e, cnt;

void dfs(int here)
{
    if (here == start)
    {
        return;
    }
    for (int i = 0; i < g[here].size(); i++)
    {
        int back = g[here][i].first;
        int cost = g[here][i].second;
        if (d[here] - cost == d[back] && !visited[here])
        {
            cnt++;
            dfs(back);
        }
    }
    visited[here] = 1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;
        v[from].push_back({to, w}); // 똑같은 간선이 주어지진 않겠지?
        g[to].push_back({from, w});
        indegree[to]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int j = 0; j < v[here].size(); j++)
        {
            int next = v[here][j].first;
            int cost = v[here][j].second;
            d[next] = max(d[next], d[here] + cost);
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }
    cin >> start >> e; // start는 필요없다
    cout << d[e] << endl;
    t[e] = 1;
    dfs(e);
    cout << cnt;
    return 0;
}