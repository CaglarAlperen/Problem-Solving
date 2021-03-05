#include <bits/stdc++.h>
 
using namespace std;
 
#define PRINT(v) for (int i : v) cout << i << " "
#define ll long long
 
int main()
{
   ll n;
   cin >> n;
   
   if (n % 4 != 3 && n % 4 != 0) {
       cout << "NO";
   }
   else {
       cout << "YES" << endl;
       vector<int> set1;
       vector<int> set2;
       
       ll sum = n*(n+1)/4;
       for (int i = n; i > 0; i--) {
           if (i <= sum) {
               set1.push_back(i);
               sum -= i;
           }
           else {
               set2.push_back(i);
           }
       }
        cout << set1.size() << endl;
        PRINT(set1);
        cout << endl;
        cout << set2.size() << endl;
        PRINT(set2);
   }
     
   return 0;
}