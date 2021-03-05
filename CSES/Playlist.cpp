#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   int n,ans = 0;
   cin >> n;
   int p[n];
   for (int i = 0; i < n; i++)
      cin >> p[i];
   set<int> s;
   int len = 0;
   for (int i = 0, j = 0; i < n; i++) {
      if (s.find(p[i]) == s.end()) {
         s.insert(p[i]);
         len++;
      }
      else {
         while (p[j] != p[i]) {
            s.erase(p[j++]);
            len--;
         }
         j++;
      }
      if (len > ans) ans = len;
   }
   cout << ans;
   return 0;
}