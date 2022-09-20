class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int len = nums.size();
        int l = 0, r = len-1, c;
        
        while (r-l > 1)
        {
            c = (r + l) / 2;
            if (nums[c] - nums[l] > 0)
                l = c;
            else 
                r = c;
        }
        
        return min(nums[0], min(nums[r],nums[l]));
    }
};