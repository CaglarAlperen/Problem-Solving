class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int len = nums.size();
        int m = nums[0];
        
        int l = 0, r = len-1, c;
        while (r - l > 1)
        {
            if (nums[l] == target) return l;
            if (nums[r] == target) return r;
            
            c = (l + r) / 2;
            if (nums[c] > target)
            {
                if (target < m && nums[c] > m)
                    l = c;
                else
                    r = c;
            }
            else 
            {
                if (nums[c] == target) return c;
                
                if (target > m && nums[c] < m)
                    r = c;
                else 
                    l = c;
            }
        }
        
        if (nums[r] == target) return r;
        else if (nums[l] == target) return l;
        else return -1;
    }
};