class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int len = nums.size();
        int res = nums[0];
        
        int _min[len];
        int _max[len];
        
        _min[0] = nums[0];
        _max[0] = nums[0];
        
        int t1,t2;
        for (int i = 1; i < len; i++)
        {
            t1 = _min[i-1] * nums[i];
            t2 = _max[i-1] * nums[i];
            
            _min[i] = min(nums[i], min(t1,t2));
            _max[i] = max(nums[i], max(t1,t2));
            
            if (_max[i] > res) res = _max[i];
        }
        
        return res;
    }
};