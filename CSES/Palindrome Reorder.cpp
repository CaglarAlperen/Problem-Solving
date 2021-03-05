#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main()
{
   string s;
   cin >> s;
   
   int count[26] = {0};
   for (char c : s) {
       count[c-65]++;
   }
   
   vector<int> even;
   vector<int> odd;
   
   for (int i = 0; i < 26; i++) {
       if (count[i] % 2 == 0) even.push_back(i);
       else odd.push_back(i);
   }
   
   if (odd.size() > 1) {
       cout << "NO SOLUTION";
       return 0;
   }
   else {
       int l,r;
       l = 0;
       r = s.length()-1;
       for (int i : even) {
           while (count[i] != 0) {
               s[l++] = 'A'+i;
               s[r--] = 'A'+i;
               count[i] -= 2;
           }
       }
       while (l <= r) {
           s[l] = 'A'+odd[0];
           l++;
       }
   }
    
    cout << s;
   return 0;
}