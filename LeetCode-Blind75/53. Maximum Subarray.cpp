class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum, max_sum;
        
        int len = nums.size();
        
        sum = nums[0];
        max_sum = sum;
        for (int i = 1; i < len; i++)
        {
            sum = max(nums[i], sum + nums[i]);
            
            if (sum > max_sum) max_sum = sum;
        }
        
        return max_sum;
    }
};