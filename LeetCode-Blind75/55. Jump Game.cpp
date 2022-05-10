class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int len = nums.size();
        bool D[len];
        memset(D, 0, len * sizeof(bool));
        D[len-1] = true;
        
        for (int i = len-2; i >= 0; i--)
        {
            for (int j = 1; j <= nums[i]; j++)
            {
                if (i + j < len)
                    D[i] = D[i] || D[i+j];
                if (D[i])
                    break;
            }
        }
        
        return D[0];
    }
};