#include <bits/stdc++.h>

using namespace std;

int formingMagicSquare(vector<vector<int>> s) {
    
    int possible_magic_squares[8][3][3] = { { {8,1,6},
                                              {3,5,7},
                                              {4,9,2} },
                                            
                                            { {4,3,8},
                                              {9,5,1},
                                              {2,7,6} },
                                              
                                            { {2,9,4},
                                              {7,5,3},
                                              {6,1,8} },
                                              
                                            { {6,7,2},
                                              {1,5,9},
                                              {8,3,4} },
                                              
                                            { {6,1,8},
                                              {7,5,3},
                                              {2,9,4} },
                                              
                                            { {8,3,4},
                                              {1,5,9},
                                              {6,7,2} },
                                              
                                            { {4,9,2},
                                              {3,5,7},
                                              {8,1,6} },
                                            
                                            { {2,7,6},
                                              {9,5,1},
                                              {4,3,8} } 
    };
    
    int costs[8];
    
    int cost;
    for (int i = 0; i < 8; i++) {
        cost = 0;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cost += abs(s[j][k] - possible_magic_squares[i][j][k]);
            }
        }
        costs[i] = cost;
    }
    
    int min = 82;
    for (int i = 0; i < 8; i++) {
        if (costs[i] < min) min = costs[i];
    }
    
    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
