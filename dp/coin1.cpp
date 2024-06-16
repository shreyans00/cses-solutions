#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
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
    // Form 2
    for (int sm = 0; sm <= x; sm++)
    {
        if (sm == 0)
            dp[sm] = 1;
        else
        {
            dp[sm] = 0;
            for (int i = 0; i < n; i++)
            {
                if (sm >= a[i])
                    dp[sm] += dp[sm - a[i]];
                dp[sm] %= mod;
            }
        }
    }
    cout << dp[x];
    return 0;
}
