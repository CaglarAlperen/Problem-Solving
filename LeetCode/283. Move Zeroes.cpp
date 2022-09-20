class Solution {
public:
    bool tailZeros(vector<int> v, int k)
    {
        for (int i = k; i < v.size(); i++)
        {
            if (v[i] != 0)
                return false;
        }
        return true;
    }
    
    void moveZeroes(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (tailZeros(nums, i))
                    return;
                nums.erase(nums.begin() + i--);
                nums.push_back(0);
            }
        }
    }
};