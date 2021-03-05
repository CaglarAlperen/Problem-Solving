#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void takeChain(vector<vector<int>> matrix, vector<vector<int>>& chain, int k) {
    
    int row = matrix.size() - 1;
    int col = matrix[0].size() - 1;
    int in[2] = {k,k};
    int vel[2] = {1,0};
    vector<int> temp;
    temp.push_back(matrix[in[0]][in[1]]);
    in[0] += vel[0];
    in[1] += vel[1];
    
    while (!(in[0] == k && in[1] == k)) {
        
        temp.push_back(matrix[in[0]][in[1]]);
        
        if (in[1] == k && in[0] == row - k) {
            vel[0] = 0;
            vel[1] = 1;
        }
        else if (in[0] == row - k && in[1] == col - k) {
            vel[0] = -1;
            vel[1] = 0;
        }
        else if (in[1] == col - k && in[0] == k) {
            vel[0] = 0;
            vel[1] = -1;
        }
        
        in[0] += vel[0];
        in[1] += vel[1];
    }
    
    chain.push_back(temp);
}

void refillMatrix(vector<vector<int>>& matrix, vector<int>& chain, int k) {
    
    
    matrix[k][k] = chain[0];
    int row = matrix.size() - 1;
    int col = matrix[0].size() - 1;
    int it_chain = 1;
    int in[2] = {k+1,k};
    int vel[2] = {1,0};
    
    while (!(in[0] == k && in[1] == k)) {
        
        matrix[in[0]][in[1]] = chain[it_chain++];
        
        if (in[1] == k && in[0] == row - k) {
            vel[0] = 0;
            vel[1] = 1;
        }
        else if (in[0] == row - k && in[1] == col - k) {
            vel[0] = -1;
            vel[1] = 0;
        }
        else if (in[1] == col - k && in[0] == k) {
            vel[0] = 0;
            vel[1] = -1;
        }
        
        in[0] += vel[0];
        in[1] += vel[1];
    }
    
}

void matrixRotation(vector<vector<int>>& matrix, int r) {

    int n = matrix.size();
    int m = matrix[0].size();
    int chain_count = min(n,m) / 2;
    
    vector<vector<int>> chain;
    
    for (int i = 0; i < chain_count; i++) {
        takeChain(matrix, chain, i);
    }
    
    for (int i = 0; i < chain_count; i++) {
        rotate(chain[i].begin(), chain[i].begin() + chain[i].size() - (r % chain[i].size()), chain[i].end());
    }
    
    for (int i = 0; i < chain.size(); i++) {
        refillMatrix(matrix, chain[i], i);
    } 
    
    for (int i = 0; i < matrix.size(); i++) {
       for (int j = 0; j < matrix[i].size(); j++) {
           cout << matrix[i][j] << " ";
       }
       cout << endl;
   }
    
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
