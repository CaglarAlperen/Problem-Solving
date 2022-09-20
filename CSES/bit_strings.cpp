#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long res = 1;
    for (int i = 0; i < n; i++)
        res = (res*2) % (int)(1e9+7);
    cout << res << endl; 

    return 0;
}