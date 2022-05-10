class Solution {
public:
    void rotateDir(vector<int>& dir)
    {
        if (dir[0] == 0 && dir[1] == 1)
        {
            dir[0] = 1;
            dir[1] = 0;
        }
        else if (dir[0] == 1 && dir[1] == 0)
        {
            dir[0] = 0;
            dir[1] = -1;
        }
        else if (dir[0] == 0 && dir[1] == -1)
        {
            dir[0] = -1;
            dir[1] = 0;
        }
        else if (dir[0] == -1 && dir[1] == 0)
        {
            dir[0] = 0;
            dir[1] = 1;
        }
    }
    
    bool canMove(vector<vector<int>>& matrix, set<vector<int>>& visited, int i, int j, vector<int> dir)
    {
        if (i + dir[0] >= matrix.size() || i + dir[0] < 0)
            return false;
        if (j + dir[1] >= matrix[0].size() || j + dir[1] < 0)
            return false;
        if (visited.find(vector<int>{i+dir[0],j+dir[1]}) != visited.end())
            return false;
        return true;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> dir = {0,1};
        set<vector<int>> visited;
        vector<int> res;
        
        int i = 0, j = 0;
        
        while (visited.size() < matrix.size() * matrix[0].size() - 1)
        {
            while (canMove(matrix, visited, i, j, dir))
            {
                res.push_back(matrix[i][j]);
                visited.insert(vector<int>{i,j});
                i += dir[0];
                j += dir[1];
            }
            rotateDir(dir);
        }
        
        res.push_back(matrix[i][j]);
        
        return res;
    }
};