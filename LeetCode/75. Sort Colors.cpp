class Solution {
public:
    bool endingTwos(vector<int> nums, int k)
    {
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] != 2)
                return false;
        }
        return true;
    }
    
    void sortColors(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (endingTwos(nums, i))
                break;
            if (nums[i] == 0)
            {
                nums.erase(nums.begin() + i);
                nums.insert(nums.begin(), 0);
            }
            else if (nums[i] == 2)
            {
                nums.erase(nums.begin() + i);
                nums.push_back(2);
                i--;
            }
        }
    }
};