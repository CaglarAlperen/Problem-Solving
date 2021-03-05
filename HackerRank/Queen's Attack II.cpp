#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void obstacle(int n, int r_o, int c_o, int r_q, int c_q, int ways[8]) {
    
    if (r_o == r_q) {
        if (c_o < c_q) ways[0] = (c_q - c_o - 1 < ways[0]) ? c_q - c_o - 1 : ways[0];
        else ways[1] = (c_o - c_q - 1 < ways[1]) ? c_o - c_q - 1 : ways[1];
    }
    else if (c_o == c_q) {
        if (r_o < r_q) ways[3] = (r_q - r_o - 1 < ways[3]) ? r_q - r_o - 1 : ways[3];
        else ways[2] = (r_o - r_q - 1 < ways[2]) ? r_o - r_q - 1 : ways[2];
    }
    else if (abs(r_q - r_o) == abs(c_q - c_o)) {
        if (c_o < c_q && r_o > r_q) ways[4] = (r_o - r_q - 1 < ways[4]) ? r_o - r_q - 1 : ways[4];
        else if (c_o > c_q && r_o > r_q) ways[5] = (r_o - r_q - 1 < ways[5]) ? r_o - r_q - 1 : ways[5];
        else if (c_o > c_q && r_o < r_q) ways[6] = (r_q - r_o - 1 < ways[6]) ? r_q - r_o - 1 : ways[6];
        else if (c_o < c_q && r_o < r_q) ways[7] = (r_q - r_o - 1 < ways[7]) ? r_q - r_o - 1 : ways[7];
    }
}

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    int ways[8];
    ways[0] = c_q - 1; //left
    ways[1] = n - c_q; //right
    ways[2] = n - r_q; //up
    ways[3] = r_q - 1; //bottom
    ways[4] = min(ways[0], ways[2]); //l_up
    ways[5] = min(ways[1], ways[2]); //r_up
    ways[6] = min(ways[1], ways[3]); //r_bot
    ways[7] = min(ways[0], ways[3]); //l_bot
    
    for (int i = 0; i < k; i++) {
        obstacle(n, obstacles[i][0], obstacles[i][1], r_q, c_q, ways);
    }
    
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        sum += ways[i];
    }
    
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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