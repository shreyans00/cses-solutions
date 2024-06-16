#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[5001][5001];
int v[5001];

// int solve(int i, int j)
// {
//     if (i > j)
//         return 0;
//     if (i == j)
//         return v[i];

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int left = v[i] + min(solve(i + 1, j - 1), solve(i + 2, j));
//     int right = v[j] + min(solve(i + 1, j - 1), solve(i, j - 2));

//     return dp[i][j] = max(left, right);
// }

signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int gap = 0; gap < n; ++gap) // fill in diagonal fashion
    {
        for (int i = 0, j = gap; j < n; ++i, ++j)
        {
            int left = v[i] + min(((i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0), ((i + 2 <= j) ? dp[i + 2][j] : 0));
            int right = v[j] + min(((i <= j - 2) ? dp[i][j - 2] : 0), ((i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0));
            dp[i][j] = max(left, right);
        }
    }
    cout << dp[0][n - 1];
}
