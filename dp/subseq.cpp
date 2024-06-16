#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> lis;
    for (int i = 0; i < n; i++)
    {
        if (lis.empty() || lis.back() < v[i])
            lis.push_back(v[i]);
        else
        {
            // replace lis[idx] with smaller element so that for that size subsequence, min value at last is v[i]
            int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[idx] = v[i];
        }
    }
    cout << lis.size();
}