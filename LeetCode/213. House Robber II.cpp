class Solution {
public:
    int rob1(vector<int>& nums)
    {
        int len = nums.size();
        
        if (len == 1)
            return nums[0];
        else if (len == 2)
            return max(nums[0], nums[1]);
        else if (len == 3)
            return max(nums[0] + nums[2], nums[1]);
        
        int D[len+1];
        memset(D, 0, (len+1)*sizeof(int));
        D[len] = 0;
        D[len-1] = nums[len-1];
        D[len-2] = nums[len-2];
        
        int res = 0;
        for (int i = len-3; i >= 0; i--)
        {
            D[i] = max(D[i+2], D[i+3]) + nums[i];
            if (D[i] > res)
                res = D[i];
        }
        
        return res;
    }
    
    int rob(vector<int>& nums) {
        
        int len = nums.size();
        
        if (len == 1)
            return nums[0];
        else if (len == 2)
            return max(nums[0], nums[1]);
        
        vector<int> nums1(nums);
        vector<int> nums2(nums);
        nums1.erase(nums1.begin() + len-1);
        nums2.erase(nums2.begin());
        
        return max(rob1(nums1), rob1(nums2));
    }
};