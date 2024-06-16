#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int dp[2][101];
int n, m;

int32_t main()
{
    cin >> n >> m;
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int last = 1; last <= m; last++)
        dp[n % 2][last] = 1;
    for (int lev = n - 1; lev >= 0; lev--)
    {
        for (int last = 1; last <= m; last++)
        {
            if (v[lev] == 0)
            {
                int ans = dp[(lev + 1) % 2][last];
                if (last + 1 <= m)
                    ans += dp[(lev + 1) % 2][last + 1];
                if (last - 1 >= 1)
                    ans += dp[(lev + 1) % 2][last - 1];
                dp[lev % 2][last] = ans % mod;
            }
            else if (abs(v[lev] - last) > 1)
                dp[lev % 2][last] = 0;
            else
                dp[lev % 2][last] = dp[(lev + 1) % 2][v[lev]] % mod;
        }
    }

    int ans = 0;
    if (v[0] == 0)
    {
        for (int i = 1; i <= m; i++)
        {
            ans += dp[1][i];
            ans %= mod;
        }
    }
    else
        ans = dp[0][v[0]];
    cout << ans;
}