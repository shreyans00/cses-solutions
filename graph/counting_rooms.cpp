#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int c = 0;
    bool vis[n][m];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && v[i][j] == '.')
            {
                c++;
                vis[i][j] = 1;
                q.push({i, j});
                while (!q.empty())
                {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (!vis[nx][ny] && nx < n && ny < m && nx >= 0 && ny >= 0 && v[nx][ny] == '.')
                        {
                            q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }
    cout << c << endl;
}