class Solution {
public:
    vector<vector<bool>> visited;
    int res = 0;
    
    void bfs(vector<vector<char>>& grid, int i, int j, int n, int m)
    {
        set<vector<int>> queue;
        queue.insert(vector<int>{i,j});
        
        while (queue.size() > 0)
        {        
            vector<int> pos = *queue.begin();
            queue.erase(queue.begin());
            visited[pos[0]][pos[1]] = true;
            
            if (pos[0] > 0)
            {
                if (!visited[pos[0]-1][pos[1]] && grid[pos[0]-1][pos[1]] == '1')
                {
                    queue.insert(vector<int>{pos[0]-1,pos[1]});
                }
            }
            if (pos[0] < n-1)
            {
                if (!visited[pos[0]+1][pos[1]] && grid[pos[0]+1][pos[1]] == '1')
                {
                    queue.insert(vector<int>{pos[0]+1,pos[1]});
                }
            }
            if (pos[1] > 0)
            {
                if (!visited[pos[0]][pos[1]-1] && grid[pos[0]][pos[1]-1] == '1')
                {
                    queue.insert(vector<int>{pos[0],pos[1]-1});
                }
            }
            if (pos[1] < m-1)
            {
                if (!visited[pos[0]][pos[1]+1] && grid[pos[0]][pos[1]+1] == '1')
                {
                    queue.insert(vector<int>{pos[0],pos[1]+1});
                }
            }
        }

        res++;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        visited.resize(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                    bfs(grid, i, j, n, m);
            }
        }
        
        return res;
    }
};