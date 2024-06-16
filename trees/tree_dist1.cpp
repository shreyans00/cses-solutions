#include <bits/stdc++.h>
using namespace std;

int solve(int node, int par, vector<int> adj[])
{
}

int main()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(1, -1, adj);
}