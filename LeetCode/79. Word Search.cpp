class Solution {
public:    
    bool exists(vector<vector<char>>& board, string word, int i, int j, int len)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() 
            || board[i][j] != word[len] || board[i][j] == '*')
            return false;
            
        len++;
        if (len == word.length())
            return true;
        
        board[i][j] = '*';
        
        bool res = exists(board, word, i-1, j, len) ||
                   exists(board, word, i, j-1, len) ||
                   exists(board, word, i+1, j, len) ||
                   exists(board, word, i, j+1, len);
        
        board[i][j] = word[len-1];
        
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (exists(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};