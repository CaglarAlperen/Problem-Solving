#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main()
{
   int n;
   cin >> n;
   
   ll ans = 1;
   for (int i = 0; i < n; i++) {
      ans *= 2;
      if (ans > 1000000007) ans %= 1000000007;
   }
   
   cout << ans;
   return 0;
}