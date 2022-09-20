class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        
        vector<int> shr;
        
        if (nums.size() == 1)
        {
            shr = nums[0];
            sort(shr.begin(), shr.end());
            return shr;
        }
        
        for (int i = 0; i < nums[0].size(); i++)
        {
            int f = nums[0][i];
            for (int j = 1; j < nums.size(); j++)
            {
                if (find(nums[j].begin(), nums[j].end(), f) == nums[j].end())
                    break;
                if (j == nums.size()-1)
                    shr.push_back(f);
            }
        }
        
        sort(shr.begin(), shr.end());
        
        return shr;
    }
};