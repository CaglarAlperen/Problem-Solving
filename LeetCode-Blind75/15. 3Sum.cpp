class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int len = nums.size();
        if (len < 3)
            return vector<vector<int>> {};
        
        int s;
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        for (int i = 0; i < len-2; i++)
        {
            while (i > 0 && i < len-2 && nums[i] == nums[i-1])
                i++;
            if (i > len-3) break;
            
            int l = i+1, r = len-1;
            s = nums[i] + nums[l] + nums[r];
            while (l < len && r > 0)
            {
                if (l == i) l++;
                if (r == i) r--;
                if (r <= l) break;
                
                s = nums[i] + nums[l] + nums[r];
                
                if (s < 0)
                    l++;
                else if (s > 0)
                    r--;
                else{
                    vector<int> v {nums[i], nums[l], nums[r]};
                    res.push_back(v);
                    while (l < r && nums[l] == nums[l+1])
                        l++;
                    l++;
                }
                
                if (l < len && r >= 0)
                    s = nums[i] + nums[l] + nums[r];
            }
        }
        
        return res;
    }
};