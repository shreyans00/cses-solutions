#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int sm = n * (n + 1) / 2;
    if (sm % 2 != 0)
    {
        cout << 0 << endl;
    }
    else
    {
        int rsm = sm / 2;
        int dp[n + 1][rsm + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= rsm; j++)
            {
                if (j == 0)
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j >= i + 1 && i > 0 ? dp[i - 1][j - (i + 1)] : 0);
                    dp[i][j] %= mod;
                }
            }
        }
        cout << dp[n - 1][rsm];
    }
}