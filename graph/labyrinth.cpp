#include <bits/stdc++.h>
using namespace std;

struct cls
{
public:
    int st, en;
    string s;
    cls(int x, int y, string str)
    {
        st = x;
        en = y;
        s = str;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    queue<cls> q;
    int vis[n][m];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
            {
                q.push(cls(i, j, ""));
                vis[i][j] = 1;
                break;
            }
        }
    }
    pair<int, int> d[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //{d,u,r,l}
    vector<char> mp = {'D', 'U', 'R', 'L'};
    bool f = false;
    while (!q.empty())
    {
        int x = q.front().st, y = q.front().en;
        string cs = q.front().s;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + d[i].first, ny = y + d[i].second;
            if (nx < n && ny < m && nx >= 0 && ny >= 0 && !vis[nx][ny])
                if (v[nx][ny] == 'B')
                {
                    cs += mp[i];
                    f = true;
                    cout << "YES\n"
                         << cs.length() << endl
                         << cs << endl;
                    break;
                }
                else if (v[nx][ny] == '.')
                {
                    q.push(cls(nx, ny, cs + mp[i]));
                    vis[nx][ny] = 1;
                }
        }
        if (f)
            break;
    }
    if (!f)
        cout << "NO";
}