#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int c = 0;
    int vis[n + 1];
    memset(vis, 0, sizeof(vis));
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            ans.push_back(i);
            c++;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (auto x : adj[cur])
                {
                    if (!vis[x])
                    {
                        q.push(x);
                        vis[x] = 1;
                    }
                }
            }
        }
    }
    cout << c - 1 << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0 || i == ans.size() - 1)
            cout << ans[i] << " ";
        else
            cout << ans[i] << " " << ans[i] << " ";
    }
}