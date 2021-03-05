#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   long n,x;
   cin >> n >> x;
   vector<pair<long,int>> v;
   int val[n] = {0};
   for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      v.push_back(make_pair(t,i));
      val[i] = t;
   }
   sort(v.begin(),v.end());
   sort(val,val+n);
   int r = distance(val,lower_bound(val,val+n,x))-1;
   int l = 0;
   while (l < r) {
      if (v[l].first + v[r].first == x) {
         cout << v[l].second + 1 << " " << v[r].second + 1 << endl;
         return 0;
      }
      if (v[l].first + v[r].first > x) r--;
      else l++;
   }
   cout << "IMPOSSIBLE";
   return 0;
}