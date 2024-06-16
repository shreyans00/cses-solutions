#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
int main()
{
    int n;
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int nm = i;
        dp[i] = 1e9;
        while (nm > 0)
        {
            dp[i] = min(dp[i], 1 + dp[i - nm % 10]);
            nm /= 10;
        }
    }
    cout << dp[n];
    return 0;
}