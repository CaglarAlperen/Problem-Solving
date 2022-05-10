class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int len = nums.size();
        int D[len];
        int res = 0;
        
        for (int i = 0; i < len; i++)
            D[i] = 1;
        
        for (int i = 0; i < len; i++)
        {
            for (int k = 0; k < i; k++)
            {
                if (nums[k] < nums[i])
                    D[i] = max(D[i], D[k] + 1);
            }
        }
        
        for (int i = 0; i < len; i++)
        {
            if (D[i] > res) res = D[i];
        }
        
        return res;
    }
};