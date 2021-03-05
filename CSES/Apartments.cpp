#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   int n,m,k,ans = 0;
   cin >> n >> m >> k;
   vector<int> apt;
   vector<int> cus;
   for (int i = 0; i < n; i++) {
       int t;
       cin >> t;
       apt.push_back(t);
   }
   for (int i = 0; i < m; i++) {
       int t;
       cin >> t;
       cus.push_back(t);
   }
   sort(apt.begin(),apt.end());
   sort(cus.begin(),cus.end());
   for (int i = 0, j = 0; i < n; i++) {
       while (j < m && cus[j] < apt[i]-k) j++;
       if (j < m && cus[j] < apt[i]+k+1) {
           ans++;
           j++;
       }
   }
   cout << ans;
   return 0;
}