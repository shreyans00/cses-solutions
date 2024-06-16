#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans;
vector<int> adj[100001];
vector<int> dis(100001, 1e9);

void dfs(int cur, vector<int> v)
{
    if (cur == n)
    {
        ans = v;
        return;
    }
    for (auto x : adj[cur])
    {
        if (dis[x] > 1 + dis[cur])
        {
            dis[x] = 1 + dis[cur];
            v.push_back(x);
            dfs(x, v);
            v.pop_back();
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> v;
    v.push_back(1);
    dis[1] = 1;
    dfs(1, v);
    if (dis[n] == 1e9)
        cout << "IMPOSSIBLE";
    else
    {
        cout << dis[n] << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    }
}