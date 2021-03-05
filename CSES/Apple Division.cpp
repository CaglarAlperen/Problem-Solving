#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
   int n;
   cin >> n;
   int arr[n];
   ll sum = 0;
   for (int i = 0; i < n; i++) {
       cin >> arr[i];
       sum += arr[i];
   }
        
   
   int ans = INT_MAX;
   for (int i = 0; i < 1<<n; i++) {
       ll s = 0;
       for (int j = 0; j < n; j++) {
           if (i & 1<<j) {
               s += arr[j];
           }
       }
       if (abs(sum - 2*s) < ans) ans = abs(sum - 2*s);
   }
   
   cout << ans;
   
   return 0;
}