#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   int n,ans = 0;
   cin >> n;
   vector<pair<int,int>> v;
   for (int i = 0; i < n; i++) {
      int f,s;
      cin >> s >> f;
      v.push_back(make_pair(f,s));
   }
   sort(v.begin(),v.end());
   for (int i = 0; i < n; i++) {
      ans++;
      int j = 1;
      while(j < n-i && v[i+j].second < v[i].first) j++;
      i += j-1;
   }
   cout << ans;
   return 0;
}