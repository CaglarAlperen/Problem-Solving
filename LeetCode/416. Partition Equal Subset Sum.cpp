class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int total = 0;
        for (int i : nums)
            total += i;
        
        if (total%2 == 1)
            return false;
        
        int target = total/2;
        
        bool DP[nums.size()+1][target+1];
        memset(DP, 0, (nums.size()+1)*(target+1)*sizeof(bool));
        
        for (int i = 1; i <= target; i++)
        {
            DP[0][i] = false;
        }
        for (int i = 0; i <= nums.size(); i++)
        {
            DP[i][0] = true;
        }
                
        for (int i = 1; i <= nums.size(); i++)
        {
            for (int j = 1; j <= target; j++)
            {
                DP[i][j] = DP[i-1][j];
                if (j - nums[i-1] >= 0)
                {
                    DP[i][j] = DP[i][j] || DP[i-1][j-nums[i-1]];
                }
            }
        }
        
        return DP[nums.size()][target];
    }
};