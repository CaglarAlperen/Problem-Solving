#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   int n,ans = 0;
   cin >> n;
   vector<int> s;
   for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      auto it = upper_bound(s.begin(),s.end(),a);
      if (it == s.end()) {
         s.push_back(a);
         ans++;
      }
      else {
         *it = a;
      }
   }
   cout << ans;
   return 0;
}