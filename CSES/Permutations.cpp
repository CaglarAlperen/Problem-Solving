#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    if (n < 4)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    int m = n/2 + 1;
    int l = m-1, r = m+1;

    while (l > 0 || r < n+1)
    {
        if (l > 0)
            cout << l-- << " ";
        if (r < n+1)
            cout << r++ << " ";
    }

    cout << m << endl;

    return 0;
}