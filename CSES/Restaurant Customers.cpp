#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   int n;
   cin >> n;
   int a[n],l[n];
   for (int i = 0; i < n; i++) {
      cin >> a[i] >> l[i];   
   }
   sort(a,a+n);
   sort(l,l+n);
   int ans = 0;
   for (int i = 0, j = 0; i < n && j < n; i++) {
      while (a[i] < l[j] && i < n) i++;
      if (i - j > ans) ans = i - j;
      j++;
   }
   cout << ans;
   return 0;
}