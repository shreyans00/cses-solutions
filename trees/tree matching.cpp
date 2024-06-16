#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<bool> arr;
bool solve(int node, int par, vector<int> adj[])
{
    bool f = 1;
    for (auto x : adj[node])
    {
        if (x != par && solve(x, node, adj))
            f = 0;
    }
    if (f == 0)
    {
        arr[node] = 1;
        // ans++;
    }
    return f;
}

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    ans = 0;
    arr.resize(n + 1);
    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(1, -1, adj);
    // cout << ans << endl;
    for (int i = 1; i <= n; i++)
        ans += arr[i];
    cout << ans;
}