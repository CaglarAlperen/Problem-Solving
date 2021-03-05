#include <iostream>
#define ll long long
using namespace std;
 
int main()
{
   int n;
   cin >> n;
   
   for (ll i = 1; i < n+1; i++) {
       if (i == 1) cout << 0 << endl;
       else if (i == 2) cout << 6 << endl;
       else cout << (i*i)*(i*i-1)/2 - (i-2)*(i-1)*4 << endl;
   }
   
   return 0;
}