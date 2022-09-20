class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int D[target+1];
        memset(D, 0, (target+1) * sizeof(int));
        D[0] = 1;
        
        for (int i = 1; i <= target; i++)
        {
            for (int num : nums)
            {
                if (i - num >= 0)
                    D[i] += D[i - num];
            }   
        }
        
        return D[target];
    }
};