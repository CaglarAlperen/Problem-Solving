#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;
    while (n > 0)
    {
        n /= 5;
        res += n;
    }
    cout << res << endl;

    return 0;
}