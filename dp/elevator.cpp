#include <bits/stdc++.h>
using namespace std;

int n, x;
int w[21];
vector<int> wt;

bool satisfy(int i, int sz)
{
    if (i == n)
        return 1;
    bool ans = 0;
    for (int j = 0; j < sz; j++)
    {
        if (wt[j] + w[i] <= x)
        {
            wt[j] += w[i];
            ans |= satisfy(i + 1, sz);
            wt[j] -= w[i];
        }
    }
    return ans;
}

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        wt.clear();
        wt.resize(i);
        fill(wt.begin(), wt.end(), 0);
        if (satisfy(0, i)) // min i weights can work
        {
            cout << i << endl;
            break;
        }
    }
}