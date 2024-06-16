#include <bits/stdc++.h>
using namespace std;

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
    bool f = 0;
    vector<int> team(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (team[i] == -1)
        {
            queue<int> q;
            q.push(i);
            team[i] = 1;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (auto x : adj[cur])
                {
                    if (team[x] == -1)
                    {
                        team[x] = (team[cur] == 1) ? 2 : 1;
                        q.push(x);
                    }
                    else if (team[x] == team[cur])
                    {
                        f = 1;
                        break;
                    }
                }
                if (f)
                    break;
            }
        }
        if (f)
            break;
    }
    if (f)
        cout << "IMPOSSIBLE";
    else
    {
        for (int i = 1; i <= n; i++)
            cout << team[i] << " ";
    }
}