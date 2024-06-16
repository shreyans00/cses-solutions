#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        adj[x].push_back({y, cost});
    }
    vector<int> dis(n + 1, 1e15);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    dis[1] = 0;
    while (!q.empty())
    {
        int cur = q.top().second, dist = q.top().first;
        q.pop();
        for (auto x : adj[cur])
        {
            if (dis[x.first] > x.second + dist)
            {
                dis[x.first] = x.second + dist;
                q.push({dis[x.first], x.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
}