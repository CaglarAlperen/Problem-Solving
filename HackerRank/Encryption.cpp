#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {

    int l = s.length();
    
    int row = floor(sqrt(l));
    int col = ceil(sqrt(l));
    
    if (row * col < l) row++;
    
    string encoded = "";
    
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (j*col + i < l) encoded += s[j*col + i];
        }
        encoded += ' ';
    }
    
    return encoded;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}