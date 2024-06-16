#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];

int main()
{
    int n, tsm = 0;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        tsm += v[i];
    }
    memset(dp, 0, sizeof(dp));
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
        dp[i][v[i]] = 1;
        for (int j = 0; j <= tsm; j++)
        {
            if (i && j >= v[i])
                dp[i][j] += dp[i - 1][j - v[i]];
            if (i)
                dp[i][j] += dp[i - 1][j];
            if (dp[i][j])
                mp[j]++;
        }
    }
    cout << mp.size() << endl;
    for (auto x : mp)
        cout << x.first << " ";
    return 0;
}