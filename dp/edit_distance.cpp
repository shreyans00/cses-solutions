#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = i | j;
            else
            {
                if (s1[i - 1] != s2[j - 1])
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                else
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[n][m];
}