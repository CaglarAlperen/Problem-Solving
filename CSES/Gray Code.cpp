#include <bits/stdc++.h>
 
using namespace std;
 
bool t[1<<16];
 
int btoi(string s) {
    int r = 0;
    int l = s.length();
    for (int i = 0; i < l; i++) {
        r += (s[l-i-1]-'0')*pow(2,i);
    }
    return r;
}
 
int main() {
    int n;
    cin >> n;
    memset(t,0,1<<n);
    string s (n,'0');
    t[0] = 1;
    cout << s << endl;
    for (int i = 1; i < 1<<n; i++) {
        for (int j = n; j > -1; j--) {
            s[j] = (s[j] == '0') ? '1' : '0';
            if (!t[btoi(s)]) {
                cout << s << endl;
                t[btoi(s)] = 1;
                break;
            }
            else s[j] = (s[j] == '0') ? '1' : '0';
        }
    }
 
    return 0;
}