class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        
        for (int i = 0; i < len; i++)
        {
            if (i != nums[i])
                return i;
        }
        
        return len;
    }
};