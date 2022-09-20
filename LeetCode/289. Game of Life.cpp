class Solution {
public:
    int calc(vector<vector<int>> board, int k, int l)
    {
        int neighbor_num = 0;
        
        for (int i = -1; i < 2; i++)
        {
            if ((k+i) < 0)
                continue;
            if ((k+i) >= board.size())
                continue;
            
            for (int j = -1; j < 2; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if ((l+j) < 0)
                    continue;
                if ((l+j) >= board[0].size())
                    continue;
                
                if (board[k+i][l+j])
                    neighbor_num++;
            }
        }
        
        if (neighbor_num < 2)
            return 0;
        if (neighbor_num > 3)
            return 0;
        if (neighbor_num == 3)
            return 1;
        return board[k][l];
    }
    
    void gameOfLife(vector<vector<int>>& board) 
    {
        vector<vector<int>> nextGen(board.size(), vector<int>(board[0].size()));
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                nextGen[i][j] = calc(board, i, j);
            }
        }
        
        board = nextGen;
    }
};