#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   string board[8];
   for (int i = 0; i < 8; i++) cin >> board[i];
   int p[8], ans = 0;
   iota(p,p+8,0);
   bool b[15];
   do {
       bool ok = 1;
       for (int i = 0; i < 8; i++) {
           ok &= board[i][p[i]] == '.';
       }
       memset(b,0,15);
       for (int i = 0; i < 8; i++) {
           if (b[i+p[i]]) ok = 0;
           b[i+p[i]] = 1;
       }
       memset(b,0,15);
       for (int i = 0; i < 8; i++) {
           if (b[i+7-p[i]]) ok = 0;
           b[i+7-p[i]] = 1;
       }
       if (ok) ans++;
   } while(next_permutation(p,p+8));
   cout << ans;
   return 0;
}