class Solution {
public:
    bool check_row(vector<vector<char>>& board, int k)
    {
        map<char, int> m;
        
        for (int i = 0; i < 9; i++)
        {
            if (board[k][i] != '.')
            {
                m[board[k][i]]++;
                if (m[board[k][i]] == 2)
                    return false;
            }
        }
        
        return true;
    }
    
    bool check_column(vector<vector<char>>& board, int k)
    {
        map<char, int> m;
        
        for (int i = 0; i < 9; i++)
        {
            if (board[i][k] != '.')
            {
                m[board[i][k]]++;
                if (m[board[i][k]] == 2)
                    return false;
            }
        }
        
        return true;
    }
    
    bool check_box(vector<vector<char>>& board, int k, int l)
    {
        map<char, int> m;
        
        for (int i = 3*k; i < 3*k+3; i++)
        {
            for (int j = 3*l; j < 3*l+3; j++)
            {
                if (board[i][j] != '.')
                {
                    m[board[i][j]]++;
                    if (m[board[i][j]] == 2)
                        return false;
                }
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i = 0; i < 9; i++)
        {
            if (!check_row(board, i))
                return false;
            if (!check_column(board, i))
                return false;
        }
        
        for(int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (!check_box(board, i, j))
                    return false;
            }
        }
        
        return true;
    }
};