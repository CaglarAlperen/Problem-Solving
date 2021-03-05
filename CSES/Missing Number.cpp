#include <iostream>
#define ll long long
using namespace std;
 
int main()
{
   long long n;
   cin >> n;    
 
   ll summ = 0;
   for (int i = 1; i < n; i++) {
      int temp;
      cin >> temp;
      summ += temp;
   }
   cout << n*(n+1)/2 - summ;
   return 0;
}