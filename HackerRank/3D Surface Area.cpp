#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) {

    int up_view = A.size() * A[0].size() * 2;
    int near_view1 = 0, near_view2 = 0;
    
    int j,i;
    for (i = 0; i < A.size(); i++) {
        near_view1 += A[i][0];
        for (j = 1; j < A[i].size(); j++) {
            near_view1 += abs(A[i][j] - A[i][j-1]);
        }
        near_view1 += A[i][j-1];
    }
    
    for (i = 0; i < A[0].size(); i++) {
        near_view2 += A[0][i];
        for (j = 1; j < A.size(); j++) {
            near_view2 += abs(A[j][i] - A[j-1][i]);
        }
        near_view2 += A[j-1][i];
    }

    return up_view + near_view1 + near_view2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}