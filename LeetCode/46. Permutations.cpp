class Solution {
public:
    vector<vector<int>> permutations;
    
    void p(vector<int> &nums, vector<int> &res)
    {
        if (nums.size() == 0)
        {
            permutations.push_back(res);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int k = nums[i];
            nums.erase(nums.begin() + i);
            res.push_back(k);
            p(nums, res);
            res.pop_back();
            nums.insert(nums.begin() + i, k);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> res;
        p(nums, res);
        return permutations;
    }
};