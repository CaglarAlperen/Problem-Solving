#include <bits/stdc++.h>
 
using namespace std;
 
stack<int> s[3];
 
int main() {
    int n;
    cin >> n;
    for (int i = n; i > 0; i--) {
        s[0].push(i);
    }
    cout << (1 << n) - 1 << endl;
    if (n % 2 == 0) {
        while (s[2].size() != n) {
            // 1 <-> 2
            if (!s[0].empty() && (s[1].empty() || s[0].top() < s[1].top())) {
                s[1].push(s[0].top());
                s[0].pop();
                cout << "1 2" << endl;
            }
            else if (!s[1].empty() && (s[0].empty() || s[1].top() < s[0].top())) {
                s[0].push(s[1].top());
                s[1].pop();
                cout << "2 1" << endl;
            }
            if (s[2].size() == n) break;
            // 1 <-> 3
            if (!s[0].empty() && (s[2].empty() || s[0].top() < s[2].top())) {
                s[2].push(s[0].top());
                s[0].pop();
                cout << "1 3" << endl;
            }
            else if (!s[2].empty() && (s[0].empty() || s[2].top() < s[0].top())) {
                s[0].push(s[2].top());
                s[2].pop();
                cout << "3 1" << endl;
            }
            if (s[2].size() == n) break;
            // 2 <-> 3
            if (!s[1].empty() && (s[2].empty() || s[1].top() < s[2].top())) {
                s[2].push(s[1].top());
                s[1].pop();
                cout << "2 3" << endl;
            }
            else if (!s[2].empty() && (s[1].empty() || s[2].top() < s[1].top())) {
                s[1].push(s[2].top());
                s[2].pop();
                cout << "3 2" << endl;
            }
        }
    } else {
        while (s[2].size() != n) {
            // 1 <-> 3
            if (!s[0].empty() && (s[2].empty() || s[0].top() < s[2].top())) {
                s[2].push(s[0].top());
                s[0].pop();
                cout << "1 3" << endl;
            }
            else if (!s[2].empty() && (s[0].empty() || s[2].top() < s[0].top())) {
                s[0].push(s[2].top());
                s[2].pop();
                cout << "3 1" << endl;
            }
            if (s[2].size() == n) break;
            // 1 <-> 2
            if (!s[0].empty() && (s[1].empty() || s[0].top() < s[1].top())) {
                s[1].push(s[0].top());
                s[0].pop();
                cout << "1 2" << endl;
            }
            else if (!s[1].empty() && (s[0].empty() || s[1].top() < s[0].top())) {
                s[0].push(s[1].top());
                s[1].pop();
                cout << "2 1" << endl;
            }
            if (s[2].size() == n) break;
            // 2 <-> 3
            if (!s[1].empty() && (s[2].empty() || s[1].top() < s[2].top())) {
                s[2].push(s[1].top());
                s[1].pop();
                cout << "2 3" << endl;
            }
            else if (!s[2].empty() && (s[1].empty() || s[2].top() < s[1].top())) {
                s[1].push(s[2].top());
                s[2].pop();
                cout << "3 2" << endl;
            }
        }
    }
 
    return 0;
}