class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int minute = 0;
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<int>> queue;
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    visited[i][j] = true;
                    queue.push_back({i,j});
                }
            }
        }
        
        while (queue.size())
        {
            bool rotten = false;
            int size = queue.size();
            for (int k = 0; k < size; k++)
            {
                int i = queue[k][0];
                int j = queue[k][1];
                
                if (i > 0 && !visited[i-1][j] && grid[i-1][j] == 1)
                {
                    grid[i-1][j] = 2;
                    visited[i-1][j] = true;
                    queue.push_back({i-1,j});
                    rotten = true;
                }
                if (i < grid.size()-1 && !visited[i+1][j] && grid[i+1][j] == 1)
                {
                    grid[i+1][j] = 2;
                    visited[i+1][j] = true;
                    queue.push_back({i+1,j});
                    rotten = true;
                }
                if (j > 0 && !visited[i][j-1] && grid[i][j-1] == 1)
                {
                    grid[i][j-1] = 2;
                    visited[i][j-1] = true;
                    queue.push_back({i,j-1});
                    rotten = true;
                }
                if (j < grid[0].size()-1 && !visited[i][j+1] && grid[i][j+1] == 1)
                {
                    grid[i][j+1] = 2;
                    visited[i][j+1] = true;
                    queue.push_back({i,j+1});
                    rotten = true;
                }
            }
            
            for (int i = 0; i < size; i++)
            {
                queue.erase(queue.begin());
            }
            
            if (rotten)
                minute++;
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }    
        }
        
        return minute;
    }
};