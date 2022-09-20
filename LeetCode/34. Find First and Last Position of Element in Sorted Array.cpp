class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        auto l_it = lower_bound(nums.begin(), nums.end(), target);
        auto r_it = upper_bound(nums.begin(), nums.end(), target);
        
        if (l_it == nums.end() || *l_it != target)
            return {-1, -1};
        else 
            return {(int)(l_it - nums.begin()) , (int)(r_it - nums.begin() - 1)};
    
    }
};