#include <bits/stdc++.h>

using namespace std;

string sortFrom(string s, int ind) {
    
    bool control = true;
    while(control) {
        control = false;
        
        for (int i = s.length()-1; i > ind; i--) {
            if (s[i] < s[i-1]) {
                char temp = s[i];
                s[i] = s[i-1];
                s[i-1] = temp;
                control = true;
            }
        }
    }
    
    return s;
}

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {

    bool changed = false;
    
    for (int i = w.length() - 2; i > -1; i--) {
        if (w[i] < w[i+1]) {
            char min = 'z';
            int j;
            for (j = w.length() - 1; j > i; j--) {
                if (w[j] <= min && w[j] > w[i]) {
                    min = w[j];
                    break;
                }
            }
            w[j] = w[i];
            w[i] = min;
            w = sortFrom(w,i+1);
            changed = true;
            break;
        }
    }
    
    return (changed) ? w : "no answer";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}