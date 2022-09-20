#include <bits/stdc++.h>

using namespace std;

unordered_set<string> s;

bool solve(string str, int n)
{
    if (s.size() == (1 << n))
        return true;
    for (int i = 0; i < n; i++)
    {
        str[i] += (str[i] == '1') ? -1 : 1;
        s.insert(str);
        if (solve(str, n))
            return true;
        s.erase(str);
    }
}

void print_result()
{
    for (string str : s)
    {
        cout << str << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    
    set<string> res;
    string code(n, '0');

    solve(code, n);
    print_result();

    return 0;
}