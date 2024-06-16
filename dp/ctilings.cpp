#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, m;
// max value of mask is 2^10-1 =1023, (since, n-> 10)
int dp[11][1 << 11];

void findall(int i, vector<int> &possibleMask, int tmask, int curmask)
{
    if (i == n)
    {
        possibleMask.push_back(tmask);
        return;
    }
    if (!(curmask & (1 << i)))
    {
        findall(i + 1, possibleMask, tmask | (1 << i), curmask);
        if (i != n - 1 && !(curmask & (1 << (i + 1))))
            findall(i + 2, possibleMask, tmask, curmask);
    }
    else
        findall(i + 1, possibleMask, tmask, curmask);
}

int sol(int j, int mask)
{
    if (j == m)
        return !mask;
    if (dp[j][mask] != -1)
        return dp[j][mask];
    vector<int> possibleMasks;
    findall(0, possibleMasks, 0, mask);
    int ans = 0;
    for (auto x : possibleMasks)
    {
        ans += sol(j + 1, x);
        ans %= mod;
    }
    return dp[j][mask] = ans;
}

int main()
{
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << sol(0, 0);
}