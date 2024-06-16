#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
#define MP make_pair

int main()
{
    int n;
    cin >> n;
    pair<int, pair<int, int>> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second.first >> a[i].second.second;
    }
    sort(a, a + n);
    long long dp[n + 1];
    for (int i = n; i >= 0; i--)
    {
        if (i == n)
            dp[i] = 0;
        else
        {
            dp[i] = dp[i + 1];
            int jg = upper_bound(a, a + n, MP(a[i].second.first, MP(INF, INF))) - a;
            dp[i] = max(dp[i], a[i].second.second + dp[jg]);
        }
    }
    cout << dp[0];
}
