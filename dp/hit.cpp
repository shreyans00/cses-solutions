#include <bits/stdc++.h>
using namespace std;

int n, x;
int w[21];
vector<int> wt;
int dp[21][21][21];
int sm(int mask)
{
    int val = 0;
    for (int i = 0; i < log2(mask); i++)
    {
        int idx = (1 << i) & mask;
        if (idx && idx <= n)
            val += w[i];
    }
    return val;
}

int func(int i, int mask, int covered)
{
    // cout << i << " " << mask << " " << covered << endl;
    if (covered == n)
        return 1;
    if (i == n || i == -1)
        return 1e9;
    if (dp[i][mask][covered] != -1)
        return dp[i][mask][covered];
    if (mask & (1 << i))
        return 1e9;
    if (sm(mask) + w[i] >= x)
    {
        return dp[i][mask][covered] = min(1 + func(i, 0, covered + 1), min(func(i + 1, mask, covered), func(i - 1, mask, covered)));
    }
    int ans = 1e9;
    for (int j = 1; j <= n; j++)
    {
        if (!(mask & (1 << j)))
        {
            ans = min(ans, min(func(i + 1, mask ^ (1 << j), covered + 1), func(i + 1, mask, covered)));
        }
    }
    return dp[i][mask][covered] = ans;
}

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    memset(dp, -1, sizeof(dp));
    cout << func(0, 0, 0);
    // cout << sm(22);
}