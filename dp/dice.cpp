#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j <= 6; j++)
        {
            if (i >= j)
                ans = (ans + dp[i - j]) % mod;
            else
                break;
        }
        dp[i] = ans;
    }
    cout << dp[n] << endl;
}