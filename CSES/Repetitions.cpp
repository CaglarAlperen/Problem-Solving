#include <iostream>
 
using namespace std;
 
int main()
{
   string str;
   cin >> str;
   char p = str[0];
   int max = 0;
   int len = 1;
   for (int i = 1; i < str.length(); i++) {
      if (str[i] == p) len++;
      else {
         if (len > max) max = len;
         len = 1;
      }
      p = str[i];
   }
   if (len > max) max = len;
 
   cout << max;
   return 0;
}