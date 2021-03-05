#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   long n,ans = 0;
   cin >> n;
   long arr[n];
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   long s = LONG_MIN;
   for(int i = 0; i < n; i++) {
      ans = max(ans + arr[i], arr[i]);
      if (ans > s) s = ans;
   }
   cout << s;
 
   return 0;
}