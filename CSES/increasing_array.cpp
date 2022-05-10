#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long res = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 1; i < n; i++)
    {
        while (arr[i] < arr[i-1])
        {
            arr[i]++;
            res++;
        }
    }

    cout << res << endl;

    return 0;
}