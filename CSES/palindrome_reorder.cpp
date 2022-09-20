#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;

    map<char, int> m;
    for (char c : str)
        m[c]++;

    vector<string> evens;
    vector<string> odds;

    for (auto const &[key, val] : m)
    {
        if (val%2)
            odds.push_back(string(val,key));
        else
            evens.push_back(string(val,key));
    }

    if (odds.size() > 1)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string res = "";
    for (string s : evens)
    {
        res.insert(res.length()/2,s);
    }
    if (odds.size())
        res.insert(res.length()/2,odds[0]);
    
    cout << res << endl;

    return 0;
}