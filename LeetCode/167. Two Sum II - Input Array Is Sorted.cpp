class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int l=0, r=numbers.size()-1;
        int sum = numbers[l] + numbers[r];
        
        while (l < r)
        {
            if (sum < target)
            {
                sum -= numbers[l++];
                sum += numbers[l];
            }
            else if (sum > target)
            {
                sum -= numbers[r--];
                sum += numbers[r];
            }
            else
            {
                return {l+1,r+1};
            }
        }
        
        return {};
    }
};