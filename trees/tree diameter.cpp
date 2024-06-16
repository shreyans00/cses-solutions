#include <bits/stdc++.h>
using namespace std;

int ans = 0;

int solve(int node, int par, vector<int> adj[])
{
    int mx1 = 0, mx2 = 0;
    for (auto x : adj[node])
    {
        if (x != par)
        {
            int subt = solve(x, node, adj);
            if (subt > mx1)
                mx2 = mx1, mx1 = subt;
            else if (subt > mx2)
                mx2 = subt;
        }
    }
    // cout << node << " " << mx1 << " " << mx2 << endl;
    ans = max(ans, mx1 + mx2 + 1);
    return mx1 + 1;
}

int main()
{
    int n;
    cin >> n;
    ans = 0;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(1, -1, adj);
    cout << ans - 1 << endl;
}