#include <bits/stdc++.h>
using namespace std;

int dp[1001][100001];

int main()
{
    int n, x;
    cin >> n >> x;
    int h[n], s[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j == 0)
                dp[i][j] = 0;
            else
            {
                if (i == 0)
                {
                    if (h[i] <= j)
                        dp[i][j] = s[i];
                    else
                        dp[i][j] = 0;
                }
                else if (h[i] <= j)
                    dp[i][j] = max(dp[i - 1][j], s[i] + dp[i - 1][j - h[i]]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int mx = 0;
    for (int i = 0; i <= x; i++)
        mx = max(mx, dp[n - 1][i]);
    cout << mx;
}