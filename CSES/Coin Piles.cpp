#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main()
{
   int t;
   cin >> t;
   
   while (t-- > 0) {
       int l,r;
       cin >> l >> r;
       if ((l + r) % 3 != 0) cout << "NO" << endl;
       else if (l < r/2 || r < l/2) cout << "NO" << endl;
       else cout << "YES" << endl;
   }
   
   return 0;
}