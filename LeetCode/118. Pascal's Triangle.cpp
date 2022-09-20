class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res = {{1}};
        if (numRows > 1)
        {
            res.push_back({1,1});
        }
        for (int i = 2; i < numRows; i++)
        {
            vector<int> v = {1,1};
            for (int j = 1; j < i; j++)
            {
                v.insert(v.begin()+j, res[i-1][j-1] + res[i-1][j]);
            }
            res.push_back(v);
        }
        
        return res;
    }
};