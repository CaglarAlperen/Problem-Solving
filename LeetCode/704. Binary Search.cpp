class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0, r = n-1, m;
        
        m = (l+r) / 2;
        
        while (nums[m] != target)
        {
            if (target < nums[l] || target > nums[r])
                return -1;
            if (nums[m] < target)
            {
                l = m+1;
                m = (l+r)/2;
            }
            else 
            {
                r = m-1;
                m = (l+r)/2;
            }
        }
        
        return m;
    }
};