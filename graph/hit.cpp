#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> v;
    v.push_back(1);
    vector<int> dis(n + 1, 1e9);
    dis[1] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    dis[1] = 0;
    while (!q.empty())
    {
        int cur = q.top().second, dist = q.top().first;
        q.pop();
        for (auto x : adj[cur])
        {
            if (dis[x] > 1 + dist)
            {
                dis[x] = 1 + dist;
                q.push({dis[x], x});
                v.push_back(x);
            }
        }
    }
    if (dis[n] == 1e9)
        cout << "IMPOSSIBLE";
    else
    {
        cout << dis[n] << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    }
    
}

 