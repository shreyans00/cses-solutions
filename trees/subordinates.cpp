#include <bits/stdc++.h>
using namespace std;

vector<int> res;

int solve(int node, vector<int> adj[])
{
    int ans = 0;
    for (auto x : adj[node])
        ans += solve(x, adj);
    res[node] = ans;
    return ans + 1;
}

int main()
{
    int n;
    cin >> n;
    res.resize(n + 1);
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i + 2);
    }
    solve(1, adj);
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
}