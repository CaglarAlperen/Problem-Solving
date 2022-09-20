class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        vector<vector<int>> queue;
        
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    visited[i][j] = true;
                    if (i > 0 && !visited[i-1][j] && mat[i-1][j] == 1)
                    {
                        visited[i-1][j] = true;
                        queue.push_back({i-1,j});
                    }
                    if (i < mat.size()-1 && !visited[i+1][j] && mat[i+1][j] == 1)
                    {
                        visited[i+1][j] = true;
                        queue.push_back({i+1,j});
                    }
                    if (j > 0 && !visited[i][j-1] && mat[i][j-1] == 1)
                    {
                        visited[i][j-1] = true;
                        queue.push_back({i,j-1});
                    }
                    if (j < mat[0].size()-1 && !visited[i][j+1] && mat[i][j+1] == 1)
                    {
                        visited[i][j+1] = true;
                        queue.push_back({i,j+1});
                    }
                }
            }
        }
        
        int step = 1;
        int last = 0;
        while (last != queue.size())
        {
            int size = queue.size();
            for (int k = last; k < size; k++)
            {
                int i = queue[k][0];
                int j = queue[k][1];
                res[i][j] = step;
                visited[i][j] = true;
                
                if (i > 0 && !visited[i-1][j] && mat[i-1][j] == 1)
                {
                    visited[i-1][j] = true;
                    queue.push_back({i-1,j});
                }
                if (i < mat.size()-1 && !visited[i+1][j] && mat[i+1][j] == 1)
                {
                    visited[i+1][j] = true;
                    queue.push_back({i+1,j});
                }
                if (j > 0 && !visited[i][j-1] && mat[i][j-1] == 1)
                {
                    visited[i][j-1] = true;
                    queue.push_back({i,j-1});
                }
                if (j < mat[0].size()-1 && !visited[i][j+1] && mat[i][j+1] == 1)
                {
                    visited[i][j+1] = true;
                    queue.push_back({i,j+1});
                }
            }
            
            last = size;
            step++;
        }
        
        return res;
    }
};