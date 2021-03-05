#include <iostream>
 
using namespace std;
 
int main()
{
   int n;
   cin >> n;
   int p;
   cin >> p;
   long sum = 0;
   for (int i = 1; i < n; i++) {
      int c;
      cin >> c;
      if (c < p) {
          sum += p - c;
      }
      else p = c;
   }   
 
   cout << sum;
   return 0;
}