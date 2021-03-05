#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   int n,m;
   cin >> n >> m;
   int c[m];
   multiset<int> s;
   for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      s.insert(t);
   }
   for (int i = 0; i < m; i++)
      cin >> c[i];
   for (int i = 0; i < m; i++) {
      auto it = s.upper_bound(c[i]);
      if (it == s.begin()) cout << "-1" << endl;
      else {
         it--;
         cout << *it << endl;
         s.erase(it);
      }
   }
   
   return 0;
}