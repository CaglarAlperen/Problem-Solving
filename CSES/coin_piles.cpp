#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a,b;
    cin >> a >> b;
    if ((a+b)%3)
    {
        cout << "NO" << endl;
        return;
    }
    if (min(a,b) < (a+b)/3) 
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();

    return 0;
}