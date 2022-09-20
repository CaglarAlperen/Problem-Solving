#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long x, y;
    cin >> x >> y;

    if (x > y) {
        if (x % 2 == 0) cout << x*x - y + 1 << endl;
        else cout << (x-1)*(x-1) + y << endl;
    }
    else {
        if (y % 2 == 1) cout << y*y - x + 1 << endl;
        else cout << (y-1)*(y-1) + x << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();

    return 0;
}