#include <bits/stdc++.h>
 
using namespace std;
 
int fact(int n) {
    if (n == 1) return 1;
    return n*fact(n-1);
}
 
void printAll(string s, int count[26], int n, int k) {
    s += (char)(n+'a');
    count[n]--;
    if (s.length() == k) {
        cout << s << endl;
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            printAll(s, count, i, k);
            count[i]++;
        } 
    }
}
 
int main() 
{ 
    string str;
    cin >> str;
    
    int count[26] = {0};
    for (char c : str) 
        count[c-'a']++;
    int divider = 1;
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) divider *= fact(count[i]);
    }
    cout << fact(str.length()) / divider << endl;
    
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            printAll("",count,i,str.length());
            count[i]++;
        }
    }
    
    
    return 0; 
} 