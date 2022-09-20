class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<bool>>& visited, int sr, int sc, int newColor, int oldColor)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
            return;
        else if (visited[sr][sc])
            return;
        else if (image[sr][sc] != oldColor)
            return;
        
        image[sr][sc] = newColor;
        visited[sr][sc] = true;
        
        dfs(image, visited, sr-1, sc, newColor, oldColor);
        dfs(image, visited, sr, sc-1, newColor, oldColor);
        dfs(image, visited, sr+1, sc, newColor, oldColor);
        dfs(image, visited, sr, sc+1, newColor, oldColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        
        dfs(image, visited, sr, sc, newColor, image[sr][sc]);
        
        return image;
    }
};