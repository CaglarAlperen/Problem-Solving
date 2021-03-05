#include <bits/stdc++.h>

using namespace std;

int region(vector<vector<int>> matrix, int n, int m, int i, int j, vector<vector<bool>>& visited) {
    if (i == n || i < 0 || j == m || j < 0) return 0;
    else if (visited[i][j]) return 0;
    else if (matrix[i][j] == 0) {
        visited[i][j] = true;
        return 0;
    } 
    else {        
        visited[i][j] = true;
        return 1 + region(matrix,n,m,i-1,j-1,visited) + region(matrix,n,m,i-1,j,visited) + region(matrix,n,m,i-1,j+1,visited) + region(matrix,n,m,i,j-1,visited) + region(matrix,n,m,i,j+1,visited) + region(matrix,n,m,i+1,j-1,visited) + region(matrix,n,m,i+1,j,visited) + region(matrix,n,m,i+1,j+1,visited);
    }
}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) {
    
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool>> visited(n);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            visited[i].push_back(false);
    int maxr = 0;
    vector<pair<int,int>> stack;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && matrix[i][j]) {
                maxr = max(maxr, region(matrix,n,m,i,j,visited));
            }
        }
    }
    return maxr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}
