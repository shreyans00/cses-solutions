#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
const int mod = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    char v[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == '*')
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (i == 0 || v[i - 1][j] == '*')
                dp[i][j] = dp[i][j - 1];
            else if (j == 0 || v[i][j - 1] == '*')
                dp[i][j] = dp[i - 1][j];
            else if (v[i - 1][j] == '*' && v[i][j - 1] == '*')
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n - 1][n - 1];
}