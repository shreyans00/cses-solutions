#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    pair<int, int> d[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<char> dir = {'U', 'D', 'L', 'R'};
    bool f = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                if (v[i][j] == 'A')
                {
                    f = 1;
                    cout << "YES\n"
                         << 0 << endl;
                    break;
                }
                if (v[i][j] == '#' || v[i][j] == 'M')
                    continue;
                int vis[n + 1][m + 1];
                memset(vis, 0, sizeof(vis));
                queue<pair<pair<int, int>, string>> q;
                vis[i][j] = 1;
                q.push({{i, j}, ""});
                int c = 0;
                while (!q.empty())
                {
                    int sz = q.size();
                    int found = 0;
                    c++;
                    string fstr;
                    while (sz--)
                    {
                        int x = q.front().first.first, y = q.front().first.second;
                        string str = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = x + d[k].first, ny = y + d[k].second;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
                            {
                                if (v[nx][ny] == '.')
                                {
                                    q.push({{nx, ny}, dir[k] + str});
                                    vis[nx][ny] = 1;
                                }
                                else if (v[nx][ny] == 'A')
                                {
                                    fstr = dir[k] + str;
                                    found = 1;
                                }
                                else if (v[nx][ny] == 'M')
                                {
                                    found = 2;
                                    fstr = "";
                                    break;
                                }
                            }
                        }
                        if (found == 2)
                            break;
                    }
                    if (found == 1)
                    {
                        cout << "YES\n"
                             << c << endl
                             << fstr << endl;
                        f = 1;
                        break;
                    }
                    else if (found == 2)
                        break;
                }
                if (f)
                    break;
            }
        }
        if (f)
            break;
    }
    if (!f)
        cout << "NO\n";
}