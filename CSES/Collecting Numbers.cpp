#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
        
    set<int> s;

    s.insert(arr[0]);
    for (int i = 1; i < n; i++) {
        if (s.find(arr[i] - 1) == s.end()) {
            s.insert(arr[i]);
        }
        else {
            s.erase(arr[i] - 1);
            s.insert(arr[i]);
        }
    }

    cout << s.size();

    return 0;
}