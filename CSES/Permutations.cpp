#include <iostream>
 
using namespace std;
 
int main()
{
   int n;
   cin >> n;
   int m = n-1;
   
   if (n < 4 && n > 1) cout << "NO SOLUTION";
   else {
   while (m > 0) {
       cout << m << " ";
       m -= 2;
   }
   while (n > 0) {
       cout << n << " ";
       n -= 2;
   }
   
   }
   
   return 0;
}