class Solution {
public:
    vector<int> permutation(vector<int> nums, int k)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((k >> i) % 2)
                res.push_back(nums[i]);
        }
        return res;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res;
        
        for (int i = 0; i < (1 << nums.size()); i++)
        {
            res.push_back(permutation(nums, i));
        }
        
        return res;
    }
};