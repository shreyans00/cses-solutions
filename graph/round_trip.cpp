#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100001];
vector<int> ans;
int start;

bool dfs(int cur, int prev, vector<bool> &vis, vector<int> &v)
{
    vis[cur] = 1;
    v.push_back(cur);
    for (auto x : adj[cur])
    {
        if (!vis[x])
        {
            if (dfs(x, cur, vis, v))
                return true;
        }
        else if (prev != x)
        {
            ans = v;
            start = x;
            return true;
        }
    }
    v.pop_back();
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n + 1, 0);
    bool f = false;
    // char remainingStack[1024];
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vector<int> v;
            if (dfs(i, -1, vis, v))
            {
                int st = 0;
                for (int i = 0; i < ans.size(); i++)
                {
                    if (ans[i] == start)
                        st = i;
                }
                cout << ans.size() - st + 1 << endl;
                for (int i = st; i < ans.size(); i++)
                {
                    cout << ans[i] << " ";
                }
                cout << ans[st] << endl;
                f = true;
                break;
            }
        }
        // cout << sizeof(remainingStack) * i << " bytes" << endl;
    }
    if (!f)
        cout << "IMPOSSIBLE\n";
}