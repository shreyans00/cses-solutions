#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int dp[a + 1][b + 1];
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            dp[i][j] = 1e9;
            if (i == j)
                dp[i][j] = 0;
            else
            {
                for (int k = 1; k <= i / 2; k++)
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
                for (int k = 1; k <= j / 2; k++)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
                // cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
    }
    cout << dp[a][b];
}