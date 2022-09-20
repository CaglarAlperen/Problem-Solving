#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    if (n % 4 == 1 || n % 4 == 2)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<int> set1;
    vector<int> set2;
    int start = 1;
    if (n % 4 == 3)
    {
        set1 = {1,2};
        set2 = {3};
        start = 4;
    }
    for (int i = start, j = n; i < j; i+=2, j-=2)
    {
        set1.push_back(i);
        set1.push_back(j);
        set2.push_back(i+1);
        set2.push_back(j-1);
    }
    cout << set1.size() << endl;
    for (int i = 0; i < set1.size(); i++)
        cout << set1[i] << " ";
    cout << endl << set2.size() << endl;
    for (int i = 0; i < set2.size(); i++)
        cout << set2[i] << " ";
    cout << endl;

    return 0;
}