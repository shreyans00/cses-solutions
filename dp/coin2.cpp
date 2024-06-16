#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[101][1000001];

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // Form 1
    for (int i = 0; i < n; i++)
    {
        for (int sm = 0; sm <= x; sm++)
        {
            if (sm == 0)
                dp[i][sm] = 1;
            else
            {
                if (sm >= a[i])
                    dp[i][sm] += dp[i][sm - a[i]];
                if (i > 0)
                    dp[i][sm] += dp[i - 1][sm];
            }
            dp[i][sm] %= mod;
        }
    }
    cout << dp[n - 1][x];
}