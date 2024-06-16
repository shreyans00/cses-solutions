#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;
vector<int> cntar;
int expir;

void generate(string s)
{
    istringstream iss(s);
    string word;
    vector<string> vs;
    while (iss >> word)
        vs.push_back(word);
    string curtok = vs[1], newtime = vs[2];
    mp[curtok] = expir + stoi(newtime);
}

void renew(string s)
{
    istringstream iss(s);
    string word;
    vector<string> vs;
    while (iss >> word)
        vs.push_back(word);
    string curtok = vs[1], newtime = vs[2];
    mp[curtok] = expir + stoi(newtime);
}

int stringToInt(const string &str)
{
    int result = 0;
    int sign = 1;
    size_t i = 0;

    // Check for negative sign
    if (str[0] == '-')
    {
        sign = -1;
        i = 1; // Start from the next character
    }

    for (; i < str.length(); ++i)
    {
        if (isdigit(str[i]))
        {
            result = result * 10 + (str[i] - '0');
        }
        else
        {
            cerr << "Invalid character in input: " << str[i] << endl;
            // Handle the error here, for example, by returning a default value or throwing an exception.
            // For now, we'll return 0 as a default value.
            return 0;
        }
    }

    return result * sign;
}

void count(string s)
{
    istringstream iss(s);
    string word;
    vector<string> vs;
    cout << endl;
    while (iss >> word)
        vs.push_back(word);
    string va = word;
    int val = stringToInt(va), ccnt = 0;
    for (auto x : mp)
    {
        if (val < x.second)
            ccnt++;
    }
    cntar.push_back(ccnt);
}

vector<int> getUnexpiredTokens(int time_to_live, vector<string> queries)
{
    int n = queries.size();
    for (int i = 1; i < n; i++)
    {
        // cout << i << " " << queries[i][0] << endl;
        if (queries[i][0] == 'g')
            generate(queries[i]);
        else if (queries[i][0] == 'r')
            renew(queries[i]);
        else
            count(queries[i]);
    }
    return cntar;
}

int main()
{
    int n;
    cin >> n;
    cin >> expir;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        arr[i] = str;
    }
    vector<int> ans = getUnexpiredTokens(expir, arr);
    // cout << "size " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}