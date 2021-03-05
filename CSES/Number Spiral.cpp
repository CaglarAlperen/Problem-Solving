#include <iostream>
#define ll long long
using namespace std;
 
void solve() {
    ll n,m;
    cin >> n >> m;
    
    if (n > m) {
        if (n % 2 == 0) cout << n*n - m + 1 << endl;
        else cout << (n-1)*(n-1) + m << endl;
    }
    else {
        if (m % 2 == 1) cout << m*m - n + 1 << endl;
        else cout << (m-1)*(m-1) + n << endl;
    }
}
 
int main()
{
   int t;
   cin >> t;
   
   for (int i = 0; i < t; i++) 
      solve();
   
   return 0;
}