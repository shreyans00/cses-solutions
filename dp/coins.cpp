#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int dp[1000001];

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int sm = 0; sm <= x; sm++)
    {
        if (sm == 0)
            dp[sm] = 0;
        else
        {
            dp[sm] = INF;
            for (int i = 0; i < n; i++)
            {
                if (sm >= a[i])
                    dp[sm] = min(dp[sm], 1 + dp[sm - a[i]]);
            }
        }
    }

    if (dp[x] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[x] << endl;
    }
}
