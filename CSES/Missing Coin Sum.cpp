#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
int main() {
 
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
        
    sort(arr,arr+n);
    
    ll missing = 1;
 
    for (int i = 0; i < n; i++) {
        if (arr[i] > missing) {
            break;
        }
        else {
            missing += arr[i];
        }
    }
 
    cout << missing;
 
    return 0;
}