#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   long n,ans = 0;
   cin >> n;
   long l[n];
   for (int i = 0; i < n; i++)
      cin >> l[i];
   sort(l,l+n);
   for (int i = 0; i < n; i++) {
      ans += abs(l[i] - l[n/2]);
   }
   cout << ans;
   return 0;
}