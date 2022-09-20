class Solution {
public:
    vector<vector<int>> res;
    
    void rec(vector<int> candidates, int from, int target, vector<int> chain, int sum)
    {
        if (from >= candidates.size())
        {
            return;
        }
        if (sum == target)
        {
            res.push_back(chain);
            return;
        }
        else if (sum > target)
        {
            return;
        }
        
        chain.push_back(candidates[from]);
        rec(candidates, from, target, chain, sum + candidates[from]);
        chain.pop_back();
        rec(candidates, from+1, target, chain, sum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        rec(candidates, 0, target, {}, 0);

        return res;
    }
};